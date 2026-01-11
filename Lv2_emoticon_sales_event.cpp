#include <vector>
#include <algorithm>
using namespace std;

int maxCost = 0, maxCnt = 0;

void dfs(int idx, vector<vector<int>>& users, vector<int>& emoticons, vector<int>& userCost)
{
    if(idx == emoticons.size())
    {
        int curCnt = 0, curCost = 0;
        for(int i = 0; i < users.size(); ++i)
        {
            if(users[i][1] <= userCost[i])
                curCnt++;
            else
                curCost += userCost[i];
        }
        
        if(maxCnt == curCnt)
            maxCost = max(maxCost, curCost);
        else if(maxCnt < curCnt)
        {
            maxCnt = curCnt;
            maxCost = curCost;
        }
        
        return;
    }

    for(int rate = 10; rate <= 40; rate += 10)
    {
        int saleCost = (emoticons[idx] / 100) * (100 - rate);
        for(int i = 0; i < users.size(); ++i)
        {
            if(users[i][0] <= rate)
                userCost[i] += saleCost;
        }
        
        dfs(idx+1, users, emoticons, userCost);
        
        for(int i = 0; i < users.size(); ++i)
        {
            if(users[i][0] <= rate)
                userCost[i] -= saleCost;
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> userCost(users.size(), 0);
    
    dfs(0, users, emoticons, userCost);
    
    answer.push_back(maxCnt);
    answer.push_back(maxCost);
    
    return answer;
}
