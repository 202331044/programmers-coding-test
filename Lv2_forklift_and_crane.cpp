#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int answer = 0;
    int n = storage.size(), m = storage[0].size();
    
    for(auto request: requests)
    {
        if(request.size() == 2)
        {
            for(int r = 0; r < n; ++r)
            {
                for(int c = 0; c < m; ++c)
                {
                    if(storage[r][c] == request[0])
                        storage[r][c] = '0';
                }
            }
            continue;
        }
        
        queue<pair<int, int>> que;
        vector<vector<bool>> visited(n+2, vector<bool>(m+2, false));
        que.push({-1, -1});
        visited[0][0] = true;
        
        while(!que.empty())
        {
            auto [cr, cc] = que.front();
            que.pop();
            
            for(int i = 0; i < 4; ++i)
            {
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                if(nr < -1 || nr > n || nc < -1 || nc > m)
                    continue;
                
                if(nr == -1 || nr == n || nc == -1 || nc == m)
                {
                    if(visited[nr + 1][nc + 1] == false)
                    {
                        visited[nr + 1][nc + 1] = true;
                        que.push({nr ,nc});
                    }
                }
                else if(storage[nr][nc] == request[0])
                {
                    visited[nr + 1][nc + 1] = true;
                    storage[nr][nc] = '0';
                }
                else if(storage[nr][nc] == '0' && visited[nr + 1][nc + 1] == false)
                {
                    visited[nr + 1][nc + 1] = true;
                    que.push({nr, nc});
                }
            }
        }
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(storage[i][j] != '0')
                answer++;
        }
    }
    
    return answer;
}
