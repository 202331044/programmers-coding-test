#include <string>
#include <vector>

using namespace std;

bool isThree(const char ch, const int& r, const int & c, vector<string>& board)
{   
    int cnt = 1;
    int dr[4][2] = {{0, 0}, {1, 2}, {1, 2}, {1, 2}};
    int dc[4][2] = {{1, 2}, {0, 0}, {1, 2}, {-1, -2}};

    for(int i = 0; i < 4; ++i)
    {
        int cnt = 1;
        for(int j = 0; j < 2; ++j)
        {
            int nr = r + dr[i][j];
            int nc = c + dc[i][j];
        
            if(nr >= 0 && nr < 3 && nc >= 0 && nc < 3 
               && board[nr][nc] == ch)
                cnt++;

            if(cnt == 3)
                 return true; 
        }
    }
    return false;
}

int solution(vector<string> board) {
    int cntO = 0, cntX = 0;
    for(int r = 0; r < 3; ++r)
    {
        for(int c = 0; c < 3; ++c)
        {
            if(board[r][c] == 'O')
                cntO++;
            else if(board[r][c] == 'X')
                cntX++;
        }
    }
    
    if(cntO == 0 && cntX == 0)
        return 1;
    else if(cntO < cntX || (cntO - cntX) > 1)
        return 0;
    
    int threeO = 0, threeX = 0;
    for(int r = 0; r < 3; ++r)
    {
        for(int c = 0; c < 3; ++c)
        {
            if(board[r][c] == 'O')
            {
                if(isThree('O', r, c, board))
                    threeO++;
            }
            else if(board[r][c] == 'X')
            {
                if(isThree('X', r, c, board))
                    threeX++;
            }
        }
    }
    
    int answer = 0;
    if((cntO - cntX) == 1)
    {
        if(threeO >= 0 && threeX == 0)
            answer = 1;
    }
    else if(cntO == cntX)
    {
        if(threeO == 0 && threeX >= 0)
            answer = 1;
    }
    return answer;
}
