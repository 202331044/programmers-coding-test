#include <vector>

using namespace std;

long long solution(int n) {
    vector<int> vec(n+1, 0);
    vec[1] = 1;
    vec[2] = 2;
    
    for(int i = 3; i <= n; ++i)
        vec[i] = (vec[i-1] + vec[i - 2]) % 1234567;

    long long answer = vec[n];

    return answer;
}
