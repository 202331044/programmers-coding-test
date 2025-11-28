#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <functional>
#include <iostream>

using namespace std;

int bfs(int N, int K, vector<vector<int>>& vec, vector<vector<int>>& distance)
{
    int answer = 0;
    vector<bool> visited(N+1, false);
    priority_queue<pair<int ,int>, vector<pair<int, int>>, 
    greater<pair<int ,int>>> que;
    que.push({0, 1});
    
    while(!que.empty())
    {
        auto [dist, city] = que.top();
        que.pop();
        
        if(visited[city]) continue;
        
        visited[city] = true;
        answer++;
        
        for(auto next: vec[city])
        {
            int w = distance[city][next] + dist;
            if(visited[next] == false && w <= K)
                que.push({w, next});
        }
    }
    
    return answer;
}

int solution(int N, vector<vector<int>> road, int K) {
    int a, b, c;
    vector<vector<int>> vec(N+1);
    vector<vector<int>> distance(N+1, vector<int>(N+1, 10000));
    
    for(int i = 0; i < road.size(); ++i)
    {
        a = road[i][0];
        b = road[i][1];
        c = road[i][2];
        
        vec[a].push_back(b);
        vec[b].push_back(a);
        distance[a][b] = min(distance[a][b], c);
        distance[b][a] = min(distance[b][a], c);
    }
    
    int answer = bfs(N, K, vec, distance);
    return answer;
}
