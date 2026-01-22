#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

void dfs(vector<string>& keys, string str, const int& feature)
{
    if(str.size() >= feature)
        return;
    
    for(int i = 0; i < feature; ++i)
    {
        if(str.size() != 0 && str[str.size()-1] >= (i + '0'))
            continue;
        
        string num = to_string(i);
        keys.push_back(str + num);
        dfs(keys, str + num, feature);
    }
}

bool isInclude(string& key, vector<string>& ckeys)
{
    for(auto ckey: ckeys)
    {
        int cnt = 0;
        for(auto ch: ckey)
        {
            if(count(key.begin(), key.end(), ch) == 1)
                cnt++;
        }
        
        if(cnt == ckey.size())
            return true;
    }
    return false;
}

int solution(vector<vector<string>> relation) {
    int row = relation.size();
    int col = relation[0].size();
    vector<string> keys, ckeys;
    
    dfs(keys, "", col);
    sort(keys.begin(), keys.end(), [](const string& a, const string& b){
            return a.size() <= b.size();
    });

    for(auto key: keys)
    {
        if(isInclude(key, ckeys))
            continue;
        
        unordered_map <string, int> map;
        bool isCkey = true;
        
        for(int i = 0; i < row; ++i)
        {
            string mapKey;
            for(int idx = 0; idx < key.size(); ++idx)
            {
                int feature = key[idx] - '0';
                mapKey += (relation[i][feature] + " ");
            }
            
            if(map[mapKey] != 0)
            {
                isCkey = false;
                break;
            }
            map[mapKey]++;
        }
        
        if(isCkey)
            ckeys.push_back(key);
    }
    
    int answer = ckeys.size();
    return answer;
}
