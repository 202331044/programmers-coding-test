#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll solution(int r1, int r2) {
    ll answer = 0;
    ll lr1 = r1, lr2 = r2;
    
    if(lr1 == lr2)
    {
        for(ll x = 1; x < lr1; ++x)
        {
            double y = sqrt(lr1 * lr1 - x * x);
            if(y == int(y))
                answer++;     
        }
        answer *= 4;
        answer += 4;
        return answer;
    }
    
    if(lr1 > lr2)
        swap(lr1, lr2);
    
    for(ll x = 1; x <= lr1; ++x)
    {
        ll y1 = ceil(sqrt(lr1 * lr1 - x * x));
        ll y2 = floor(sqrt(lr2 * lr2 - x * x));
        answer += (y2 - y1 + 1);
    }
    
    answer -= 1;
    
    for(ll x = lr1 + 1; x < lr2; ++x)
    {
        ll y2 = floor(sqrt(lr2 * lr2 - x * x));
        answer += y2;
    }
    
    ll num = (lr2 - lr1 + 1) * 4;
    answer *= 4;
    answer += num;
    
    return answer;
}
