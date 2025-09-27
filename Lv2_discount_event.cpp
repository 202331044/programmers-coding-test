#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
   
    unordered_map<string ,int> map;
    unordered_map<string ,int> tmp;
    int cnt = 10, start = 0, answer = 0;
    
    for(int i = 0; i < want.size(); ++i)
        map[want[i]] = number[i];
    
    for(int end = 0; end < discount.size(); ++end)
    {
        string curr = discount[end];
        tmp[curr]++;
        cnt--;
        
        if(map[curr] == 0)
        {
            while(start <= end)
            {
                cnt++;
                tmp[discount[start]]--;
                start++;
            }
            continue;
        }
        
        if(tmp[curr] == map[curr] && cnt == 0)
        {
            answer++;
            cnt++;
            tmp[discount[start]]--;
            start++;
        }
        else if(tmp[curr] > map[curr])
        {
            while(start <= end)
            {
                tmp[discount[start]]--;
                cnt++;
                start++;
                
                if(tmp[curr] == map[curr])
                    break;
            }
        }
    }
    
    return answer;
}
