#include <string>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    bool check = false;
    
    while(n > 0)
    {
       int num = n % 3;
        if(check)
        {
            if(num != 0) check = false;
            num = num > 0 ? num - 1 : 2;
            
            if(n < 3 && num == 0) break;
        }
        
        if(num == 1 || num == 2)
            answer = to_string(num) + answer;   
        else
        {
            answer = '4' + answer;
            check = true;
        }
        n /= 3;
    }
    return answer;
}
