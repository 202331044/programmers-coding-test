#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000001;

struct degree
{
    int in = 0;
    int out = 0;
};

int bfs(int start, vector<vector<int>>& routes, vector<degree>& deg)
{
    vector<bool> visited(MAX, false);
    queue<int> que;
    
    que.push(start);
    visited[start] = true;
    
    int node = 0, edge = 0;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        node++;
        edge += deg[cur].out;
            
        for(const auto& next: routes[cur])
        {
            if(visited[next] == true)
                continue;
            
            visited[next] = true;
            que.push(next);
        }
    }
    
    int idx = 0;
    
    if(node == edge) idx = 1;
    else if(node == edge + 1) idx = 2;
    else idx = 3;
    
    return idx;    
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4, 0);
    vector<degree> deg(MAX);
    vector<vector<int>> routes(MAX);
    
    for(const auto& edge: edges)
    {
        int u = edge[0];
        int v = edge[1];
        
        routes[u].push_back(v);
        deg[u].out++;
        deg[v].in++;
    }
    
    int newNode = 0;
    for(int i = 1; i < MAX; ++i)
    {
        if(deg[i].in == 0 && deg[i].out > 1)
        {
            newNode = i;
            break;
        }     
    }
    
    answer[0] = newNode;
    for(const auto& start: routes[newNode])
    {
        int idx = bfs(start, routes, deg);
        answer[idx]++;
    }
    
    return answer;
}
