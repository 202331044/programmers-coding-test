#include <vector>
#include <queue>
#include <utility>

using namespace std;

void bfs(const int& m, const int& n, const int& r, const int&c, vector<vector<int>>& picture, vector<vector<bool>>& visited, int& number_of_area, int& max_size_of_one_area)
{
    int area_size = 0;
    queue<pair<int, int>> que;
    
    que.push({r, c});
    visited[r][c] = true;
    number_of_area++;
    
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    
    while(!que.empty())
    {
        auto [cr, cc] = que.front();
        que.pop();
        area_size++;
        
        for(int i = 0; i < 4; ++i)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && 
               picture[nr][nc] == picture[r][c] && visited[nr][nc] == false)
            {
                que.push({nr, nc});
                visited[nr][nc] = true;
            }     
        }      
    }
    
    max_size_of_one_area = max(max_size_of_one_area, area_size);
    return;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    for(int r = 0; r < m; ++r)
    {
        for(int c = 0; c < n; ++c)
        {
            if(picture[r][c] == 0 || visited[r][c] == true)
                continue;
            bfs(m, n, r, c, picture, visited, number_of_area, max_size_of_one_area);
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}
