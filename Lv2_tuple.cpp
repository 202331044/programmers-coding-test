#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) { 
    
    int pos = 1;
    int max = 0;
    string str;
    unordered_map<int, int> map;
    
    while(pos < s.length())
    {
        if(s[pos] == '{')
        {
            pos++;
        }
        else if(s[pos] == '}' || s[pos] == ',')
        {
            if(str.length() != 0)
            {
                int num = stoi(str);
                map[num]++;
                if(max < map[num])
                    max = map[num];
                str = "";
            }
            pos++;
        }
        else
        {
            str += s[pos];
            pos++;
        }
    }
    
    vector<int> answer(max, 0);
    for(auto it= map.begin(); it != map.end(); ++it)
        answer[max - it->second] = it->first;
    
    return answer;
}
