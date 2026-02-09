#include <vector>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    int totalA = 0, totalB = 0;
    vector<vector<int>> vec(info.size() + 1, vector<int>(m, 0));
    int idx = 1;
    for(auto thing: info)
    {
        int a = thing[0], b = thing[1];
        totalA += a;
        totalB += b;
        
        vec[idx][b] = max(vec[idx][b], a);
        int rem = m - 1 - b;
        
        for(int i = 0; i < idx; ++i)
            for(int j = 0; j <= rem; ++j)
                vec[idx][j + b] = max(vec[idx][j + b], vec[i][j] + vec[idx][b]);
        
        ++idx;
    }
    
    int maxVal = 0;
    for(int i = 0; i < info.size() + 1; ++i)
    {
        for(int j = 0; j < m; ++j)
            maxVal = max(maxVal, vec[i][j]);
    }
    
    int answer = -1;
    if(totalA - maxVal < n)
        answer = totalA - maxVal;

    return answer;
}
