#include <stack>
#include <string>
#include <cmath>

using namespace std;

bool isPrimeNumber(long long num)
{
    if(num < 2)
        return false;
    else if(num == 2)
        return true;
    
    int snum = sqrt(num);
    for(int i = 2; i <= snum; ++i)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    stack<int> s;
    int answer = 0;

    while(n != 0)
    {
        s.push(n%k);
        n /= k;
    }
   
    while(!s.empty())
    {
        string str;
        while(s.empty() == false && s.top() != 0)
        {
            str += s.top() + '0';
            s.pop();
        }
                
        if(!s.empty())
            s.pop();  
        
        if(str.length() == 0)
            continue;

        if(isPrimeNumber(stoll(str)))
            answer++;
    }
    return answer;
}
