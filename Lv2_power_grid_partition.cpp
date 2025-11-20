#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    int u, v;
    vector<vector<int>> vec(n+1);
    
    for(int i = 0; i < n - 1 ; ++i)
    {
        u = wires[i][0], v = wires[i][1];
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    for(int j = 0; j < n - 1; ++j)
    {
        int cnt = 0;
        u = wires[j][0], v = wires[j][1];
        
        vector<bool> visited(n + 1, false);
        visited[u] = visited[v] = true;
        queue<int> q;
        q.push(u);
        
        while(!q.empty())
        {
            int node = q.front();
            cnt++;
            q.pop();
            
            for(auto next: vec[node])
            {
                if(visited[next] == false)
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        
        answer = min(answer, abs(2*cnt - n));
    }
    return answer;
}
