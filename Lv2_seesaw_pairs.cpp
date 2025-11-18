#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long combination(int n)
{
    long long sum = 1;
    for(int i = n; i > n - 2; --i)
        sum *= i;
    
    return sum / 2;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    int length[3] = {2, 3, 4};
    unordered_map<int, int> map, equal;
    
    for(int i = 0; i < weights.size(); ++i)
    {
        for(auto len : length)
            map[weights[i] * len]++;
        equal[weights[i]]++;
    }
    
    for(auto it = map.begin(); it != map.end(); ++it)
    {
        if(it->second == 2)
            answer++;
        else if(it->second >= 3)
            answer += combination(it->second);
    }
    
    for(auto it = equal.begin(); it != equal.end(); ++it)
    {
        if(it->second == 2)
            answer -= 2;
        else if(it->second >= 3)
            answer -= combination(it->second) * 2;
    }
    
    return answer;
}
