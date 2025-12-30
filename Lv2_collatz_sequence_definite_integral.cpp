#include <vector>
using namespace std;

void collatz(int k, vector<double>& height)
{
    height.push_back(k);
    while(k > 1)
    {
        if(k % 2 == 0)
            k /= 2;
        else
            k = k * 3 + 1;
        
        height.push_back(k);
    }
}

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> height;
    collatz(k, height);
    
    int n = height.size() - 1;
    vector<double> dp(n + 1, 0);
    
    for(int i = 1; i < dp.size(); ++i)
        dp[i] = dp[i-1] + ((height[i] + height[i-1])/2);

    vector<double> answer;
    for(auto& r : ranges)
    {
        int s = r[0];
        int e = n + r[1];

        if(s > e)
            answer.push_back(-1);
        else
            answer.push_back(dp[e] - dp[s]);
    }
    
    return answer;
}
