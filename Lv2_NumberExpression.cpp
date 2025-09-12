#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0;
    int sum = 0;
    int start = 1;
    
    for(int i = 1; i <= n; ++i)
    {
        sum += i;
        while(sum >= n)
        {
            if(sum == n)
               answer++;
            sum -= start;
            start++;
        }
    }
    
    return answer;
}
