#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int oneCnt1 = 0, oneCnt2 = 0;
    int answer = 0;
    int tmp = n;
    
    while(tmp != 0)
    {
        if(tmp % 2 == 1)
            oneCnt1++;
        tmp /= 2;
    }

    for(int i = n + 1; i <= 1000000; ++i)
    {
        tmp = i;
        oneCnt2 = 0;
        
        while(tmp != 0)
        {
            if(tmp % 2 == 1)
                oneCnt2++;
            tmp /= 2;
        }
        
        if(oneCnt1 == oneCnt2)
        {
            answer = i;
            break;
        }      
    }

    return answer;
}
