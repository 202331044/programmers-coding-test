#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int answer = 0;

void dfs(const int& r, const int& h, const int& w, vector<pair<int ,int>>& pos)
{
    if(pos.size() == w)
    {
        answer++;
        return;
    }
    
    for(int c = 0; c < w; ++c)
    {
        bool isQueen = true;
        for(auto [y, x]: pos)
        {
            if(c == x || (abs(r - y) == abs(c - x)))
            {
                isQueen = false;
                break;
            }
        }
        
        if(isQueen)
        {
            pos.push_back({r, c});
            dfs(r + 1, h, w, pos);
            pos.pop_back();
        }
    }
}

int solution(int n) {
    int h = n, w = n;
    int row = 0;
    vector<pair<int, int>> pos;

    dfs(row, h, w, pos);
    
    return answer;
}
