#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    
    auto it = max_element(arr.begin(), arr.end());
    int maxVal = *it;
    int answer = maxVal;
    bool check = true;
    
    while(check)
    {
        check = false;
        for(int i = 0; i < arr.size(); ++i)
        {
            if(answer % arr[i] == 0)
                continue;
            else
            {
                answer += maxVal;
                check = true;
                break;
            }
        }
    }
    
    return answer;
}
