#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    int answer = 1;
    
    for(vector<string> tmp: clothes)
    {
        map[tmp[1]]++;
    }
    
    for(auto it = map.begin(); it != map.end(); ++it)
    {
        answer *= (it->second) + 1;
    }
    
    answer -= 1;
    
    return answer;
}
