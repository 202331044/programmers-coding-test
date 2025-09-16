#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> vec(100001);
    vec[0] = 0;
    vec[1] = 1;
    
    for(int i = 2; i <= n; ++i)
    {
        vec[i] = (vec[i-1] + vec[i-2]) % 1234567;;
    }
    
    int answer = vec[n];
    return answer;
}
