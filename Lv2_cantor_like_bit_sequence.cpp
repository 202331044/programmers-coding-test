#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

void dc(int& answer, ll s, ll e, ll l, ll r)
{
    if(r < s || l > e)
        return;
    
    if(s == e)
    {
        answer++;
        return;
    }

    ll interval = (e - s + 1) / 5;
    for(int i = 0; i < 5; ++i)
    {
        if(i == 2)
            continue;
        
        ll ns = s + interval * i;
        ll ne = ns + interval - 1;
        
        dc(answer, ns, ne, l, r);
    }
}

int solution(int n, ll l, ll r) {
    int answer = 0;
    ll s = 1, e = pow(5, n);
    
    dc(answer, s, e, l, r);
    
    return answer;
}
