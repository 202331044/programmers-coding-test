#include <algorithm>
using namespace std;
using ll = long long;

int gcd(int a, int b)
{
    if(a < b) swap(a, b);
    
    while(b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    
    return a;
}

ll solution(int w, int h) {
    ll answer = (ll)w * h;
    int d = gcd(w, h);
    ll squares = ((ll)w/d + (ll)h/d - 1) * d; 
    answer -= squares;
    
    return answer;
}
