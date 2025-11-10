#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int s = 0, e = k, cnt = k;
    int max, idx;
    
    while(cnt && e < number.size())
    {
        max = -1;
        idx = 0;
        
        for(int i = s; i <= e; ++i)
        {
            if(max < (number[i] - '0'))
            {
                max = (number[i] - '0');
                idx = i;
            }
        }
        answer += max + '0';
        if(answer.size() == number.size() - k)
            return answer;
        
        cnt -= (idx - s);
        s = idx + 1;
        e = s + cnt;
    }
    
    while(s < number.size())
        answer += number[s++];
    
    return answer;
}
