#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int size = name.size();
    
    for(int i = 0; i < size; ++i)
    {
        int num1 = name[i] - 65;
        int num2 = 26 - (name[i] - 65);
        
        if(name[i] != 'A')
            answer += num1 < num2 ? num1 : num2;
    }
    

    int idx1 = 0, idx2 = 0;
    
    for(int i = 0; i < size; ++i)
    {
        if(name[i] != 'A')
            idx1 = i;
        if(name[size - 1 - i] != 'A')
            idx2 = i + 1;
    }
    
    int minVal = min(size - 1, min(idx1, idx2));
    int left = 0, right = left + 1;
    
    while(right < size)
    {
        while(name[right] == 'A')
            right++;
        
        minVal = min(minVal, min(left * 2 + (size - right), (size - right) * 2 + left));
        
        left = right;
        right = left+1;
    }
   
    answer += minVal;
    return answer;
}
