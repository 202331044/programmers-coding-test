#include <vector>

using namespace std;

vector<int> answer(2, 0);

void dc(int r, int c, int len, vector<vector<int>>& arr)
{
    int num = arr[r][c];
    int half = len/2;
    
    for(int i = r; i < r + len; ++i)
    {
        for(int j = c; j < c + len; ++j)
        {
            if(arr[i][j] != num)
            {
                dc(r, c, half, arr);
                dc(r + half, c, half, arr);
                dc(r, c + half , half, arr);
                dc(r + half, c + half, half, arr);
                return;
            }
        }
    }
    
    answer[num]++;
}

vector<int> solution(vector<vector<int>> arr) {

    dc(0, 0, arr.size(), arr);
    
    return answer;
}
