#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <deque>
using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<tuple<int, string, int>> works;
    
    for(const auto& p: plans)
    {
        int h = stoi(p[1].substr(0, 2));
        int m = stoi(p[1].substr(3, 2));
        int start = 60 * h + m;
        works.push_back({start, p[0], stoi(p[2])});
    }
    
    sort(works.begin(), works.end());
    
    int idx = 1;
    int curTime = get<0>(works[0]);
    deque<tuple<int, string, int>> dq;
    
    dq.push_front(works[0]);

    while(!dq.empty())
    {
        auto [start, name, playTime] = dq.front();
        dq.pop_front();
        
        if(idx >= works.size())
        {
            curTime += playTime;
            answer.push_back(name);
        }      
        else if(get<0>(works[idx]) >= curTime + playTime)
        {
            curTime += playTime;
            answer.push_back(name);
            
            if(dq.empty())
            {
                curTime = get<0>(works[idx]);
                dq.push_front(works[idx++]);
            } 
        }
        else
        {
            int nextStart = get<0>(works[idx]);
            playTime -= (nextStart - curTime);
            curTime = nextStart;
            
            dq.push_front({start, name, playTime});
            dq.push_front(works[idx++]);
        }
    }
    
    return answer;
}
