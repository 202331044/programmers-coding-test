#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string splitString(string& str)
{
    string u, v, tmp;
    if(str.size() == 0)
        return u;
    
    int left = 0, right = 0;
    bool check = false;
    stack<char> stk;
    
    for(int idx = 0; idx < str.size(); ++idx)
    {
        u += str[idx];
        if(str[idx] == '(') left++;
        else right++;
        
        if(!stk.empty() && (stk.top() == '(' && str[idx] == ')'))
            stk.pop();
        else
            stk.push(str[idx]);
            
        if((left == right) && (left != 0))
        {
            check = (stk.size() == 0) ? true : false;
            idx++;
            if(idx < str.size())
                v += str.substr(idx, (str.size() - idx));
            break;
        }
    } 
    
    if(check && (u.size() == str.size()))
        return u;

    if(check)
    {
        u += splitString(v);
        return u;
    }
    else
    {
        string tmp;
        tmp += '(';
        tmp +=  splitString(v);
        tmp += ')';
        for(int i = 1; i < u.size() - 1; ++i)
        {
            if(u[i] == '(')
                tmp += ')';
            else
                tmp += '(';
        }
        return tmp;
    }
}

string solution(string p) {
    string answer = "";
    answer = splitString(p);
    return answer;
}
