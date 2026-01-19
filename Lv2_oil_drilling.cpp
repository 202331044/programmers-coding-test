#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

void bfs(const int& n, const int& m, const int& r, const int& c, vector<vector<int>>& land, vector<vector<bool>>& visited, vector<int>& cols)
{
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    int cnt = 0;
    unordered_set <int> set;
    queue<pair<int, int>> que;
    que.push({r, c});
    visited[r][c] = true;
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        que.pop();
        set.insert(cc);
        cnt++;
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if(visited[nr][nc] == false && land[nr][nc] == 1)
                {
                    que.push({nr, nc});
                    visited[nr][nc] = true;
                }      
            }
        }  
    }
    
    for(auto it = set.begin(); it != set.end(); ++it)
        cols[*it] += cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land.size();
    int m = land[0].size();
    vector<int> cols(m, 0);
    vector<vector<bool>> visited(n, vector<bool>(m));
    
    for(int r = 0; r < n; ++r)
    {
        for(int c = 0; c < m; ++c)
        {
            if(land[r][c] == 1 && visited[r][c] == false)
                bfs(n, m, r, c, land, visited, cols);
        }
    }
    
    for(int i = 0; i < m; ++i)
        answer = max(answer, cols[i]);
        
    return answer;
}
