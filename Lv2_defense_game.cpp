#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < enemy.size(); ++i)
    {
        answer = i + 1;
        pq.push(enemy[i]);
        
        if(pq.size() > k)
        {
            n -= pq.top();
            if(n < 0)
            {
                answer--;
                break;
            }
            pq.pop();
        }
    }
    return answer;
}
