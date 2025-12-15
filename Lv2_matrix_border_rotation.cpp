#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void fillVector(int rows, int columns, vector<vector<int>>& vec)
{
    int num = 1;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < columns; ++j)
            vec[i][j] = num++;
    }
}

int rotateClockwise(int x1, int y1, int x2, int y2, vector<vector<int>>& vec)
{
    int tmp = vec[x1][y1];
    int minVal = 10001;
    
    for(int c = y1 + 1; c <= y2; ++c)
    {
        minVal = min(tmp, minVal);
        swap(vec[x1][c], tmp);
    }
            
    for(int r = x1 + 1; r <= x2; ++r)
    {
        minVal = min(tmp, minVal);
        swap(vec[r][y2], tmp);
    }

    for(int c = y2 -1; c >= y1; --c)
    {
        minVal = min(tmp, minVal);
        swap(vec[x2][c], tmp);
    }

    for(int r = x2 - 1; r >= x1; --r)
    {
        minVal = min(tmp, minVal);
        swap(vec[r][y1], tmp);
    }
    
    return minVal;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> vec(rows, vector<int>(columns));
    vector<int> answer;
    fillVector(rows, columns, vec);

    for(auto query : queries)
    {
        int x1 = query[0] - 1;
        int y1 = query[1] - 1;
        int x2 = query[2] - 1;
        int y2 = query[3] - 1;
        
        answer.push_back(rotateClockwise(x1, y1, x2, y2, vec));
    }
    
    return answer;
}
