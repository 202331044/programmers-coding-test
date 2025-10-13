#include <string>
#include <cctype>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(string str1, string str2) {
    unordered_map<string, int> map1;
    unordered_map<string, int> map2;
    int a = 0, b = 0;
    int answer;
    
    for(int i = 0; i < str1.size() - 1; ++i)
    { 
        if(!isalpha(str1[i]) || !isalpha(str1[i+1]))
            continue;
        else   
        {
            string str;
            str += tolower(str1[i]);
            str += tolower(str1[i+1]);
            map1[str]++;
        }
    }
    
    for(int j = 0; j < str2.size() - 1; ++j)
    {
        if(!isalpha(str2[j]) || !isalpha(str2[j+1]))
            continue;
        else   
        {
            string str;
            str += tolower(str2[j]);
            str += tolower(str2[j+1]);
            map2[str]++;
        }
    }
    
    for(auto m1 = map1.begin(); m1 != map1.end(); ++m1)
    {
        auto m2 = map2.find(m1->first);
        if(m2 != map2.end())
        {
            a += min(m1->second, m2->second);
            b += max(m1->second, m2->second);
        }
        else
            b += m1->second;
    }
    
    for(auto m2 = map2.begin(); m2 != map2.end(); ++m2)
    {
        if(map1.find(m2->first) == map1.end())
            b += m2->second;
    }

    if(a ==0 && b == 0)
        answer = 65536;
    else
        answer = (float(a)/float(b) * 65536);
    
    return answer;
}
