#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int minVal, maxVal;
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for(int i = 0; i < A.size(); ++i)
    {
         minVal = A[i];
         maxVal = B[i];       
        answer += minVal * maxVal;
    }
    
    return answer;
}
