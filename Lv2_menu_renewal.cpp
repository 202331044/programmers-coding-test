#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int idx, string& str, string tmp, unordered_map<string ,int>& map)
{
    for(int i = 0; i < str.size(); ++i)
    {
        if(idx >= i)
            continue;
        map[tmp + str[i]]++;
        dfs(i, str, tmp + str[i], map);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string ,int> map;
    vector<vector<pair<string, int>>> vec(11);

    for(auto str: orders)
    {
        sort(str.begin(), str.end());
        dfs(-1, str, "", map);
    } 
       
    for(auto it = map.begin(); it != map.end(); ++it)
    {
        int len = it->first.size();
        int cnt = it->second;
        string menu = it->first;

        if(vec[len].size() == 0)
            vec[len].push_back({menu, cnt});
        else if(vec[len][0].second < cnt)
            vec[len][0] = {menu, cnt};
        else if(vec[len][0].second == cnt)
            vec[len].push_back({menu, cnt});       
    }
    
    for(int i = 0 ; i < course.size(); ++i)
    {
        int idx = course[i];
        int tmp = 2;
        for(auto t: vec[idx])
        {
            if(tmp <= t.second)
            {
                answer.push_back(t.first);
                tmp = t.second;
            }              
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
