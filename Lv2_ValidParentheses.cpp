#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> stk;
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(')
            stk.push(s[i]);
        else
        {
            if(stk.empty() == false && stk.top() == '(')
                stk.pop();
            else
                stk.push(s[i]);
        }    
    }
    
    bool answer = true;
    
    if(!stk.empty())
        answer = false;
    
    return answer;
}
