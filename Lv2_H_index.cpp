#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    vector<int> count(10001, 0);
    int answer = 0, sum = 0;
    
    for(auto p: citations)
    {
        count[p]++;
    }
    
    for(int i = 10000; i >= 0; --i)
    {
        sum += count[i];
        if(sum >= i)
        {
            answer = i;
            break;
        }    
    }

    return answer;
}
