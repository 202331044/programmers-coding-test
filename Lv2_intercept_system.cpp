#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end(), [](const auto& a, const auto& b)
         {
             if(a[1] != b[1])
                 return a[1] < b[1];
             else
                 return a[0] < b[0];
         });
    
    int answer = 1;
    int s = targets[0][1];
    
    for(int i = 1; i < targets.size(); ++i)
    {
        if(s <= targets[i][0])
        {
            answer++;
            s = targets[i][1];
        }
    }
    
    return answer;
}
