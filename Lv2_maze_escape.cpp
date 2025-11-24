#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int bfs(vector<string>& maps, pair<int ,int>& start, pair<int ,int>& dst, char ch)
{   
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int row = maps.size(), col = maps[0].size();
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<pair<int, pair<int ,int>>> que;
    que.push({0, start});
    visited[start.first][start.second] = true;
    
    while(!que.empty())
    {
        auto curr = que.front();
        int cnt = curr.first;
        auto [r,c] = curr.second;
        que.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = r + dy[i];
            int nc = c + dx[i];            
            if(nr >= 0 && nr < row && nc >= 0 && nc < col)
            {
                if(visited[nr][nc] || maps[nr][nc] == 'X') continue;
                
                if(maps[nr][nc] == ch)
                {
                    dst = {nr, nc};
                    return cnt + 1;
                } 
                
                visited[nr][nc] = true;
                que.push({cnt + 1, {nr, nc}});
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    pair<int, int> start, dst1, dst2;
    
    for(int i = 0; i < maps.size(); ++i)
    {
        for(int j = 0; j < maps[i].size(); ++j)
        {
            if(maps[i][j] == 'S')
                start = {i, j};
        }
    }
    
    int cnt1 = bfs(maps, start, dst1, 'L');
    if(cnt1 == -1)
        return cnt1;
    
    int cnt2 = bfs(maps, dst1, dst2, 'E');
    if(cnt2 == -1)
        return cnt2;
    
    return cnt1 + cnt2;
}
