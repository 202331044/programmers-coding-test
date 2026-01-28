#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

vector<int> solution(ll begin, ll end) {
    vector<int> answer;
    for(ll s = begin; s <= end; ++s)
    { 
        if(s == 1)
            answer.push_back(0);
        else
        {
            int res = 1;
            ll lim = sqrt(s);
            
            for(ll num = 2; num <= lim; ++num)
            {
                if(s%num == 0)
                { 
                    if(s/num <= 10000000)
                    {
                        res = s/num;
                        break;
                    }        
                    else
                        res = res > num ? res : num;
                }                   
            }
            answer.push_back(res);
        }  
    }
    return answer;
}
