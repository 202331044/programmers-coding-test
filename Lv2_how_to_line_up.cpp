#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long factorial(int n)
{
    long long result = 1;
    for(int i = 1; i <= n ; ++i)
        result *= i;
    
    return result;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> vec(n);
    long long sum = 0, num = 0;
    
    for(int i = 0; i < n; ++i)
        vec[i] = i + 1;
    
    while(--n)
    {
        num = factorial(n);
        for(int j = 0; j < vec.size(); ++j)
        {
            if(j == vec.size() - 1 || sum + (num * j) + 1 >= k)
            {
                if(sum + (num * j) + 1 > k)
                    --j;
                answer.push_back(vec[j]);
                vec.erase(vec.begin() + j);
                sum += num * j;
                break;
            }
        }
    }
    
    if(answer.size() != n)
        answer.push_back(vec[0]);
    
    return answer;
}
