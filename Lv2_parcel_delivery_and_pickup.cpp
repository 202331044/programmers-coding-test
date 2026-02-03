#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int pIdx = n - 1, dIdx = n - 1;
    int remP = 0, remD = 0;
    
    while(pIdx >= 0 || dIdx >= 0)
    {
        if(pIdx >= 0)
        {
            if(pickups[pIdx] - remP <= 0)
            {
                remP -= pickups[pIdx--];
                continue;
            }
            else
            {
                pickups[pIdx] -= remP;
                remP = 0;
            }
        }
        
        if(dIdx >= 0)
        {
             if(deliveries[dIdx] - remD <= 0)
            {
                remD -= deliveries[dIdx--];
                continue;
            }
            else
            {
                deliveries[dIdx] -= remD;
                remD = 0;
            }
        }
             
        answer += max(pIdx + 1, dIdx + 1) * 2;
        
        if(pIdx >= 0)
        {
            if(pickups[pIdx] - cap <= 0)
            {
                remP = cap - pickups[pIdx];
                --pIdx;
            }
            else
                pickups[pIdx] -= cap;
        }
        
        if(dIdx >= 0)
        {
            if(deliveries[dIdx] - cap <= 0)
            {
                remD = cap - deliveries[dIdx];
                --dIdx;
            }
            else
                deliveries[dIdx] -= cap;
        }
    }
    
    return answer;
}
