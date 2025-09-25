#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int tmpA = a, tmpB = b;
    
    while(tmpA != tmpB)
    {
        tmpA = (tmpA+1)/2;
        tmpB = (tmpB+1)/2;
        answer++;
        if(tmpA == tmpB)
            break;
    }
    
    return answer;
}
