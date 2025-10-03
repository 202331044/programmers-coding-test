#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    
    int days = 0 , cnt = 0;
    vector<int> answer;
    
    for(int i = 0; i < progresses.size(); ++i)
    {
        if(days * speeds[i] >= (100 - progresses[i]))
        {
            cnt++;
            continue;
        }          
        else
        {            
            if(cnt != 0)
            {
                answer.push_back(cnt);
                cnt = 0;
            }
            
            int tmp = (100 - progresses[i]) / speeds[i];
            if((100 - progresses[i]) % speeds[i] != 0)
                tmp++;
            days += (tmp - days);
            cnt++;
        }
    }
    
    if(cnt != 0)
        answer.push_back(cnt);
    
    return answer;
}
