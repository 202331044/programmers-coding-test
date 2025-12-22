#include <string>

using namespace std;

string transform(const string& str)
{
    if(str.empty()) return "";
    
    string u, v;
    int balance = 0;
    int n = str.size();
    bool isCorrect = true;

    for(int idx = 0; idx < n; ++idx)
    {
        char c = str[idx];
        u += c;
        
        balance += (c == '(') ? 1 : -1;
        if(balance < 0) isCorrect = false;
            
        if(balance == 0)
        {
            v = str.substr(idx + 1);
            break;
        }
    } 
    
    if(isCorrect)
    {
        u += transform(v);
        return u;
    }
    else
    {
        string result = "(";
        result +=  transform(v);
        result += ')';
        
        for(int i = 1; i < u.size() - 1; ++i)
          result += (u[i] == '(') ? ')' : '(';
        
        return result;
    }
}

string solution(string p) {
    string answer = transform(p);
    return answer;
}
