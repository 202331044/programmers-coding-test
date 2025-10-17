#include <string>
#include <vector>

using namespace std;

string n_base(int n, int num)
{
    string digits = "0123456789ABCDEF";
    string str;
    
    if(num == 0)
        return "0";
    
    while(num > 0)
    {
        str = digits[num % n] + str;
        num /= n;
    }
    return str;
}

string solution(int n, int t, int m, int p) {
    string str;
    string answer = "";
    int pos = p;
    
    for(int i = 0; str.length() < t * m; ++i)
        str += n_base(n, i);
    
    while(t--)
    {
        answer += str[pos- 1];
        pos += m;
    }

    return answer;
}
