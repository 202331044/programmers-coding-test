#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    
    int h = 0, w = 0, tmp = 0;
    
    for(int i = 1; i <= yellow; ++i)
    {
        if(yellow % i == 0)
        {
            tmp = 0;
            tmp = i*2 + (yellow/i) * 2 + 4;

            if(tmp == brown)
            {
                h = i + 2;
                w = (yellow/i) + 2;
                if(w >= h)
                    break;
            }
        }
    }
    
    vector<int> answer = {w, h};
    return answer;
}
