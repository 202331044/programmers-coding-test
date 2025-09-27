#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.size();
  
    for(int start = 0; start < size; ++start)
    {
        stack<char> stk;
        for(int i = start; i < s.size(); ++i)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
                if(s[i] == ')')
                    break;
                if(s[i] == ']')
                    break;
                if(s[i] == '}')
                    break;
            }
            else
            {
                char c = stk.top();
                if(c == '(' && s[i] == ')')
                    stk.pop();
                else if(c == '[' && s[i] == ']')
                    stk.pop();
                else if(c == '{' && s[i] == '}')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        
        if(stk.empty())
           answer++;
        s += s[start];
    }

    return answer;
}
