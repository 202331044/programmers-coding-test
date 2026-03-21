#include <queue>
#include <vector>

using namespace std;

int bfs(const int& n, vector<vector<int>>& computers)
{
    int cnt = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; ++i)
    {
        if(visited[i] == true)
            continue;
        
        visited[i]  = true;
        queue<int> que;
        que.push(i);
        cnt++;
        
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            
            for(int idx = 0; idx < n; ++idx)
            {
                if(computers[cur][idx] == 1 && visited[idx] == false)
                {
                    visited[idx] = true;
                    que.push(idx);
                }
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = bfs(n, computers);
    return answer;
}
