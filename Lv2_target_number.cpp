#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int sum, int pos, int& target)
{
    if(pos == numbers.size() && sum == target)
        answer++;
    
    if(pos < numbers.size())   
    {
        sum += numbers[pos];
        dfs(numbers, sum, pos + 1, target);
        
        sum -= (numbers[pos] * 2);
        dfs(numbers, sum, pos + 1, target);
    }
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    return answer;
}
