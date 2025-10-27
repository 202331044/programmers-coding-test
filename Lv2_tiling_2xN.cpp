#include <vector>

using namespace std;

const int MOD = 1000000007;
int solution(int n) {
    vector<int> dp(n+1, 1);
    
    for(int i = 2; i <=n; ++i)
        dp[i] = ((dp[i-1] % MOD) + (dp[i-2] % MOD)) % MOD;
    
    int answer = dp[n];
    return answer;
}
