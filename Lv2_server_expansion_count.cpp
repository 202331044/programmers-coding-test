#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0, servers = 0;
    queue<pair<int ,int>> que;
    
    for(int i = 0; i < players.size(); ++i)
    {     
        int n = players[i] / m;
        if(!que.empty() && que.front().first <= i)
        {
            servers -= que.front().second;
            que.pop();
        }
        
        if(servers >= n)
            continue;       
            
        if(que.empty())
        {
            answer += n;
            que.push({i + k, n});
            servers += n;
        }
        else
        {
            int num = n - servers;
            servers = n;
            answer += num;
            que.push({i + k, num});
        }
    }
    
    return answer;
}
