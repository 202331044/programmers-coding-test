#include<vector>
#include <queue>
#include <utility>

using namespace std;

int height, width;

int bfs(vector<vector<int>>& maps, vector<vector<bool>>& visited)
{
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    queue<pair<int, pair<int, int>>> que;
    que.push({1, {0, 0}});
    visited[0][0] = true;
    
    while(!que.empty())
    {
        auto [cnt, pos] = que.front();
        auto [r, c] = pos;
        que.pop();
        
        if(r == height - 1 && c == width - 1)
            return cnt;
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if(nr < height && nr >= 0 && nc < width && nc >= 0)
            {
                if(maps[nr][nc] == 1 && visited[nr][nc] == false)
                {
                    visited[nr][nc] = true;
                    que.push({cnt+1, {nr, nc}});
                }
            }
        }    
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    height = maps.size();
    width = maps[0].size();
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    
    int answer = bfs(maps, visited);
    return answer;
}
