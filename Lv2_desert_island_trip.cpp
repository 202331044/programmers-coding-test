#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int W,H;

int bfs(int r, int c, vector<vector<bool>>& visited, vector<string>& maps)
{
    int result = 0;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    queue<pair<int, int>> que;
    que.push({r, c});
    visited[r][c] = true;
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        result += maps[cr][cc] - '0';
        que.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr >= 0 && nr < H && nc >= 0 && nc < W)
            {
                if(maps[nr][nc] != 'X' && visited[nr][nc] == false)
                {
                    que.push({nr, nc});
                    visited[nr][nc] = true;
                }   
            }
        }
    }
    
    return result;
}

vector<int> solution(vector<string> maps) {
    H = maps.size();
    W = maps[0].size();
    vector<int> answer, tmp;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            if(visited[i][j] == false && maps[i][j] != 'X')
                tmp.push_back(bfs(i, j, visited, maps));
        }
    }
    
    if(!tmp.empty())
    {
        sort(tmp.begin(), tmp.end());
        if(tmp[0] == 0)
            answer.push_back(-1);
        else
            answer = tmp;
    }
    else if(tmp.empty())
        answer.push_back(-1);
    
    return answer;
}
