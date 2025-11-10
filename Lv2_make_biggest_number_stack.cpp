#include <string>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> stk;
    int cnt = k;
    
    for(int i = 0; i < number.size(); ++i)
    {   
        while(!stk.empty() && cnt > 0 && stk.top() < number[i])
        {
            stk.pop();
            cnt--;
        }
        stk.push(number[i]);
    }
    
    while(cnt--)
        stk.pop();
    
    while(!stk.empty())
    {
        answer = stk.top() + answer;
        stk.pop();
    }
    
    return answer;
}
