#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;
void dfs(int n, int idx, int preNum, vector<int>& vec, vector<bool>& visited, vector<vector<int>>& q, vector<int>& ans)
{
    if(vec[4] != 0)
    {
        vector<int> cnt(q.size(), 0);
        for(int j = 0; j < q.size(); ++j)
        {
            for(int i = 0; i < 5; ++i)
            {
                auto it = find(q[j].begin(), q[j].end(), vec[i]);
                if(it != q[j].end())
                    cnt[j]++;  
            }
            
            if(cnt[j] != ans[j])
                return;
        }
        
        answer++;
        return;
    }
    
    for(int i = preNum + 1; i <= n; ++i)
    {
        if(visited[i] == true)
            continue;
        
        visited[i] = true;
        vec[idx] = i;
        dfs(n, idx+1, i, vec, visited, q, ans);
        
        visited[i] = false;
        vec[idx] = 0;
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> vec(5, 0);
    vector<bool> visited(n, false);
    
    dfs(n, 0, 0, vec, visited, q, ans);
    
    return answer;
}
