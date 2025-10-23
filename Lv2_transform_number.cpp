#include <vector>

using namespace std;

const int MAX = 1000000;

int solution(int x, int y, int n) {
    vector<int> dp(y + 1, MAX);
    dp[x] = 0;
    
    for(int i = x; i <= y; ++i)
    {
        if(i - n >= x)
           dp[i] = min(dp[i-n] + 1, dp[i]);
        if(i / 2 >= x && i % 2 == 0)
           dp[i] = min(dp[i/2] + 1, dp[i]);
        if(i / 3 >= x && i % 3 == 0)
           dp[i] = min(dp[i/3] + 1, dp[i]);
    }
    
    int answer = (dp[y] == MAX) ? -1 : dp[y];
    return answer;
}
