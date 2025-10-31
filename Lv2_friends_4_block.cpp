#include <string>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool check = true;
    
    while(check)
    {
        check = false;
        set<pair<int ,int>> s;
        
        for(int r = 0; r < m - 1; ++r)
        {
            for(int c = 0; c < n - 1; ++c)
            {
                if(board[r][c] == ' ')
                    continue;
                
                char ch = board[r][c];
                if(board[r][c+1] == ch && 
                   board[r+1][c] == ch && board[r+1][c+1] == ch)
                {
                    check = true;
                    s.insert({r, c});
                    s.insert({r, c + 1});
                    s.insert({r + 1, c});
                    s.insert({r + 1, c + 1});
                }  
            }
        }
        
       for(auto [r, c]: s)
       {
           board[r][c] = ' ';
           answer++;
       }
        
        for(int c = 0; c < n; ++c)
        {
            for(int r = m - 1; r > 0; --r)
            {
                if(board[r][c] == ' ')
                {
                    int idx = r - 1;
                    while(idx >= 0)
                    {
                        if(board[idx][c] == ' ')
                            idx--;
                        else
                            break;
                    }
                    
                    if(idx >= 0)
                        swap(board[idx][c], board[r][c]);
                }
            }
        }  
    }
    
    return answer;
}
