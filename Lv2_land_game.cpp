#include <vector>

using namespace std;

int solution(vector<vector<int> > land)
{
    int row = land.size();
    int col = 4;
    int maxVal = 0, answer = 0;
    
    for(int r = 1; r < row; ++r)
    {
        for(int c = 0; c < col; ++c)
        {
            maxVal = 0;
            for(int t = 0; t < col; ++t)
            {
                if(c == t)
                    continue;
                else
                {
                    if(maxVal < land[r][c] + land[r-1][t])
                        maxVal = land[r][c] + land[r-1][t];
                }
            }
            land[r][c] = maxVal;
        }
    }
    
    for(int i = 0; i < col; ++i)
    {
        if(answer < land[row-1][i])
            answer = land[row-1][i];
    }
    return answer;
}
