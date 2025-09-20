#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    
    int size, cnt = 0, answer = 0;
    vector<pair<int, int>> vec(10000001, {-1, -1});
    
    for(int i = 0; i < tangerine.size(); ++i)
    {
        size = tangerine[i];
        
        if(vec[size].first != -1)
            vec[size].second += 1;
        else
            vec[size] = {size, 1};
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for(int i = 0; i < k; ++i)
    {
        if(cnt >= k)
            break;
        cnt += vec[i].second;
        answer++;
    }

    return answer;
}
