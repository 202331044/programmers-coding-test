#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<pair<int, int>> s;
    vector<int> answer(numbers.size(), -1);
    int cnt = 0;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(s.empty())
            s.push({numbers[i], cnt++});
        else
        {
            while(s.empty() == false && s.top().first < numbers[i])
            {
                answer[s.top().second] = numbers[i];
                s.pop();
            }
            s.push({numbers[i], cnt++});
        }
    }

    return answer;
}
