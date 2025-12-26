#include<vector>
#include <algorithm>
#include <array>

using namespace std;

const int INF = 1e9;
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int H = board.size();
    int W = board[0].size();
    array<int ,3> dr = {-1, -1, 0}, dc = {0, -1, -1}, arr = {INF, INF, INF};
    vector<vector<int>> dp = board;
    
    for(int r = 0; r < H; ++r)
    {
        for(int c = 0; c < W; ++c)
        {
            if(board[r][c] == 0)
                continue;
            
            for(int i = 0; i < 3; ++i)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < H && nc >= 0 && nc < W)
                    arr[i] = dp[nr][nc];
                else
                    arr[i] = 0;
            }
            
            dp[r][c] = min({arr[0], arr[1], arr[2]}) + 1;
            answer = max(answer, dp[r][c] * dp[r][c]);
        }
    }

    return answer;
}
