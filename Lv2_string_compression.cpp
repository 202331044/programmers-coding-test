#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = s.size();
    int size = s.size();
    
    for(int unit = 1; unit <= size / 2; ++unit)
    {
        int cnt = 0, len = 0;
        string pre;

        for(int idx = 0; idx < size; idx += unit)
        {
            string cur;
            if(size - idx >= unit)
                cur = s.substr(idx, unit);
            else
            {
                len += size - idx;
                break;
            }
        
            if(pre.empty() || pre == cur)
            {
                pre = cur;
                cnt++;
            }
            else
            {
                if(cnt > 1)
                    len += to_string(cnt).size();
                len += pre.size();
                
                pre = cur;
                cnt = 1;
            }
        }
        
        if(!pre.empty())
        {
            if(cnt > 1)
                len += to_string(cnt).size();
            len += pre.size();
        }
        
        answer = min(answer, len);
    }
    
    return answer;
}
