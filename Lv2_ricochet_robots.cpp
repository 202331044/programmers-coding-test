#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int H, W;
int bfs(pii& start, vector<string>& board)
{
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<pii> que, pos;
    visited[start.first][start.second] = true;
    
    for(int i = 0; i < 4; ++i)
    {
        que.push({0, i});
        pos.push({start.first, start.second});
    }
            
    while(!que.empty())
    {
        auto [cnt, state] = que.front();
        auto [r, c] = pos.front();
        que.pop();
        pos.pop();

        while(r >= 0 && r < H && c >= 0 && c < W)
        {
            r += dr[state];
            c += dc[state];
            if(r < 0 || c < 0 || r >= H || c >= W || board[r][c] == 'D')
            {
                r -= dr[state];
                c -= dc[state];
                break;
            }
        }
        
        if(board[r][c] == 'G')
            return cnt + 1;
        
        if(visited[r][c])
            continue;
        
        visited[r][c] = true;
        for(int j = 0; j < 4; ++j)
        {
            que.push({cnt + 1, j});
            pos.push({r, c});   
        }
    }
    return -1;
}

int solution(vector<string> board) {
    H = board.size();
    W = board[0].size();
    pii start;
    
    for(int i = 0; i < H; ++i)
    {
        for(int j = 0; j < W; ++j)
        {
            if(board[i][j] == 'R')
            {
                start.first = i;
                start.second = j;
                break;
            }
        }
    }
    
    int answer = bfs(start, board);
    return answer;
}
