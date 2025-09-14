#include <iostream>
#include <string>

using namespace std;

int solution(string s)
{
    int answer = -1;
    int size = s.size();
    int left = 1;
    int pos = 0;
    
    while(left < s.size())
    {
        if(pos < 0)
        {
            pos++;
            s[pos] = s[left];
        }
        else if(s[pos] != s[left])
        {
            pos++;
            s[pos] = s[left];
        }
        else
        {
            pos--;
            size -= 2;
        }
        
        left++;
    }

    if(size == 0)
        answer = 1;
    else
        answer = 0;

    return answer;
}
