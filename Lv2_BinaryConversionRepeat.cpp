#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(string s) {
    
    int zeroCnt = 0;
    int changeCnt = 0;
    
    while(s != "1")
    {
        int size = s.size();
        int oneCnt = 0;
        
        for(int i = 0; i < size; ++i)
        {
            if(s[i] == '1')
                oneCnt++;
            else
                zeroCnt++;
        }
        
        string tmp;
        while(oneCnt > 0)
        {
            tmp = to_string(oneCnt%2) + tmp;
            oneCnt /= 2;
        }
        
        changeCnt++;
        s = tmp;
    }
    
    vector<int> answer = {changeCnt, zeroCnt};
    return answer;
}
