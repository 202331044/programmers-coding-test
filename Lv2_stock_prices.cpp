#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    int price, idx;
    int size = prices.size();
    vector<int> answer(size);
    stack<pair<int, int>> stk;
    
    for(int i = 0; i < size; ++i)
    {
        if(stk.empty())
            stk.push({i, prices[i]});
        else
        {
            idx = stk.top().first;
            price = stk.top().second;
            
            if(prices[i] >= price)
                stk.push({i, prices[i]});
            else
            {
                while(!stk.empty() && prices[i] < price)
                {
                    answer[idx] = (i - idx);
                    stk.pop();
                    idx = stk.top().first;
                    price = stk.top().second;
                }
                stk.push({i, prices[i]});
            }
        }
    }
    
    while(!stk.empty())
    {
        idx = stk.top().first;
        price = stk.top().second;
        answer[idx] = (size - 1 - idx);
        stk.pop();
    }
    return answer;
}
