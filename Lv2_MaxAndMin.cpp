#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    istringstream iss(s);
    
    int num;
    iss >> num;
    int min = num, max = num;
    
    while(iss >> num)
    {
        if(min > num)
            min = num;
        if(max < num)
            max = num;
    }
      
    
    string answer = to_string(min) + " " + to_string(max);
    return answer;
}
