#include <iostream>

using namespace std;

int step(int pos)
{
    if(pos == 1)
        return 1;
    else if(pos <= 0)
        return 0;
    else
    {
        if(pos % 2 == 0)
            return step(pos/2);
        else
            return step(pos/2) + 1;
    }
}

int solution(int n)
{
    int ans = step(n);
    return ans;
}
