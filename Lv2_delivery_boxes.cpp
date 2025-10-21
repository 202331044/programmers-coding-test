#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int cnt = 1, answer = 0;
    stack<int> stk;
    
    for(int i = 0; i < order.size(); ++i)
    {
        if(order[i] == cnt)
        {
            cnt++;
            answer++;
        }
        else
        {
            if(!stk.empty() && stk.top() == order[i])
            {
                stk.pop();
                answer++;
            }
            else
            {
                while(order[i] != cnt)
                {
                    stk.push(cnt++);
                    if(order[i] < cnt)
                        return answer;
                }
                answer++;
                cnt++;
            }
        }
    }
    return answer;
}
