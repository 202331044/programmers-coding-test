#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0, sum = 0;
    queue<int> que;
    
    while(idx < truck_weights.size())
    {
        if(que.size() == bridge_length)
        {
            sum -= que.front();
            que.pop();
        }
        
        if(sum + truck_weights[idx] <= weight && que.size() + 1 <= bridge_length)
        {
            answer++;
            sum += truck_weights[idx];
            que.push(truck_weights[idx++]);
        }
        else
        {
            answer++;
            que.push(0);
        }
    }
    
    answer += bridge_length; 
    
    return answer;
}
