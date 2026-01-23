#include <cmath>

using namespace std;
using ll = long long;

long long solution(int k, int d) {
    ll answer = 0;
    ll maxX = (d/k) * k;
    ll r2 = (ll)d * d;
    for(ll x = maxX; x >= 0; x -= k)
    {
        ll x2 = x * x;
        ll y = sqrt(r2 - x2);
        answer += (y / k) + 1;
    }
    return answer;
}
