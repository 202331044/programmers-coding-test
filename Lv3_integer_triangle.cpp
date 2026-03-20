#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int h = triangle.size();
    
    vector<int> pre;
    pre.push_back(triangle[0][0]);
    
    for(int i = 1; i < h; ++i)
    {
        int w = pre.size();
        vector<int> post(triangle[i].size(), 0);
        
        for(int j = 0; j < w; ++j)
        {
            if(triangle[i][j] + pre[j] > post[j])
                post[j] = triangle[i][j] + pre[j];
            if(triangle[i][j + 1] + pre[j] > post[j + 1])
                post[j + 1] = triangle[i][j + 1] + pre[j];
        }
        pre = post;
    }
    
    auto it = max_element(pre.begin(), pre.end());
    int answer = *it;
    
    return answer;
}
