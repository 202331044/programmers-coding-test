#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<int, bool> a, pair<int, bool> b)
{
    if(a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, bool>> vec;
    int answer = 0, cnt = 0;
    
    for(int i = 0; i < book_time.size(); ++i)
    {
        int shour = stoi(book_time[i][0].substr(0, 2)) * 60;
        int sminute = stoi(book_time[i][0].substr(3, 2)); 
        vec.push_back({shour + sminute, 1});
        
        int ehour = stoi(book_time[i][1].substr(0, 2)) * 60;
        int eminute = stoi(book_time[i][1].substr(3, 2)) + 10;
        vec.push_back({ehour + eminute, 0});
    }
    
    sort(vec.begin(), vec.end(), cmp);
    
    for(int  j = 0; j < vec.size(); ++j)
    {
        auto [time, state] = vec[j];
 
        if(state)
            cnt++;
        else
            cnt--;
        
        answer = max(answer, cnt);
    }

    return answer;
}
