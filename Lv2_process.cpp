#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int cnt = 0, answer = 0;
    queue<pair<int, int>> que;
    priority_queue<int> pq(priorities.begin(), priorities.end());
    
    for(auto p: priorities)
    {
        que.push({cnt++, p});
    }
    
    while(1)
    {
        auto process = que.front();
        que.pop();
        
        if(process.second == pq.top())
        {
            pq.pop();
            answer++;
            if(process.first == location)
                return answer;
        }
        else
            que.push(process);
    }
}
