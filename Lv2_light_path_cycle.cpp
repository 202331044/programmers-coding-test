#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void go(vector<int>& answer, vector<vector<vector<bool>>>& routes, 
        vector<string>& grid, const int& startX, const int& startY, 
        const int& startD, const int& h, const int& w)
{
    int x = startX, y = startY, d = startD;
    int dist = 0;
    
    while(1)
    {
        if(routes[y][x][d] == true)
        {
            if(startX == x && startY == y && startD == d && dist != 0)
                answer.push_back(dist);
            break;
        }
        routes[y][x][d] = true;
        dist++;
        
        if(grid[y][x] == 'S')
        {
            if(d == 0) x += 1;
            else if(d == 1) y += 1;
            else if(d == 2) x -= 1;
            else y -= 1;  
        }
        else if(grid[y][x] == 'L')
        {
            if(d == 0) y -= 1;
            else if (d == 1) x += 1;
            else if(d == 2) y += 1;
            else x -= 1;
            d = (d + 3) % 4;
        }
        else
        {
            if(d == 0) y += 1;
            else if(d == 1) x -= 1;
            else if(d == 2) y -= 1;
            else x += 1;
            d = (d + 1) % 4;
        }
        if(x < 0) x = w - 1;
        if(y < 0) y = h - 1;
        if(x >= w) x = 0;
        if(y >= h) y = 0;  
    }
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int h = grid.size(), w = grid[0].length();
    vector<vector<vector<bool>>> routes(h, vector<vector<bool>> 
                                           (w, vector<bool>(4, false)));
    
    int startX, startY, startD;
    int x, y, d;
    for(int r = 0; r < h; ++r)
    {
        for(int c = 0; c < w; ++ c)
        {
            for(int idx = 0; idx < 4; ++ idx)
            {
                startX = c, startY = r, startD = idx;
                if(!routes[startY][startX][startD])
                    go(answer, routes, grid, startX, startY, startD, h, w);
             }    
        }
    }
 
    sort(answer.begin(), answer.end());
    return answer;
}
