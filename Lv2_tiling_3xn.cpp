#include <vector>

using namespace std;

int solution(int n) {
    const int MOD =  1000000007;
    
    long long dp[5001] = {0, };
    long long sum = 0;
    dp[0] = 1;
    dp[2] = 3;
    
    for(int i = 4; i <= n; i += 2)
    {
        sum = (sum + dp[i - 4]) % MOD;
        dp[i] = ((dp[i - 2] * dp[2]) % MOD + (sum * 2) % MOD) % MOD;
    }
    
    return dp[n];
}
