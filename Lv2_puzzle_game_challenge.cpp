#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
using ll = long long;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int size = diffs.size();
    int minLv = 0, maxLv = 0, answer = 0;
    int preLv, curLv;
    
    ll remain = limit - times[0];    
    vector<tuple<int, int, int>> vec(size);
    vec[0] = {diffs[0], times[0], 0};
    
    for(int i = 1; i < size; ++i)
    {
        vec[i] = {diffs[i], times[i], times[i-1]};
        remain -= times[i];
    }
    
    sort(vec.begin(), vec.end(), greater<tuple<int, int, int>>());
    answer = curLv = maxLv = get<0>(vec[0]);

    if(remain == 0)
        return maxLv;
    
    while(1)
    {
        preLv = curLv;
        curLv = (minLv + maxLv)/2;
        ll total = 0;
        
        for(int i = 0; i < size; ++i)
        {
            if(curLv >= get<0>(vec[i]))
            {
                maxLv = curLv;
                answer = min(answer, curLv);
                break;
            }
                
            total += (get<0>(vec[i]) - curLv) * (get<1>(vec[i]) + get<2>(vec[i]));
            if(total > remain)
            {
                minLv = curLv;
                break;
            }
        }
        if(curLv == preLv)
            break;
    }    
    return answer;
}
