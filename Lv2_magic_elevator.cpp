#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey)
    {
        int num = storey % 10;
        if(num > 5)
        {
            answer += 10 - num;
            storey += 10;
        }
            
        else if(num < 5)
            answer += num;
        else
        {
            if((storey / 10) % 10 < 5)
                answer += num;
            else
            {
               answer += 10 - num;
               storey += 10;
            } 
        }
        storey /= 10;
    }
    
    return answer;
}
