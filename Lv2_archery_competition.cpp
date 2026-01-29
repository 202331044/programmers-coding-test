#include <vector>
#include <algorithm>

using namespace std;

void computeLion(const int& n, const int& lion, const int& apeach, vector<int>& info, vector<int>& score, vector<int>& cnt)
{
    int lionCnt = 0;
    int lionScore = 0, apeachScore = 0;
    
    for(int i = 0; i < 10; ++i)
    {
        if(info[9 - i] + 1 > n)
            return;
        
        if((lion & (1 << i)) > 0)
        {
            lionScore += (i + 1);
            lionCnt += info[9 - i] + 1;
        }
        else if((apeach & (1 << i)) > 0)
            apeachScore += (i + 1);
    }
    
    if(lionCnt <= n)
    {
        score[lion] = lionScore - apeachScore;
        cnt[lion] = lionCnt;
    }
    
    return; 
}

bool isIdx(const int& cmp, const int& idx, vector<int>& cnt, vector<int>& score)
{
    if(cnt[cmp] < cnt[idx]) return true;
    else if(cnt[cmp] > cnt[idx]) return false;
    
    for(int i = 0; i < 10; ++i)
    {
        if((idx & (1 << i)) > 0 && (cmp & (1 << i)) > 0) continue;
        else if((idx & (1 << i)) > 0) return false;
        else if((cmp & (1 << i)) > 0) return true;
    }
    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> score(1 << 10, -55);
    vector<int> cnt(1 << 10, 0);
    
    int apeach = 0;
    for(int i = 0; i < 10; ++i)
    {
        if(info[9 - i] > 0)
            apeach = (apeach | (1 << i)); 
    }
    
    for(int lion = 0; lion < (1 << 10); ++lion)
        computeLion(n, lion, apeach, info, score, cnt);
    
    int idx = 0;
    int maxVal = -55;
    
    for(int i = 0; i < (1 << 10); ++i)
    {
        if(maxVal < score[i])
        {
            maxVal = score[i];
            idx = i;
        }
    }
    
    if(maxVal <= 0)
    {
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0; i < (1 << 10); ++i)
    {
        if(score[i] == maxVal)
        {
            if(isIdx(i, idx, cnt, score))
                idx = i;
        }
    }
    
    answer.push_back(n - cnt[idx]);
    for(int i = 0; i < 10; ++i)
    {
        if((idx & (1 << i)) > 0)
            answer.push_back(info[9-i] + 1);
        else
            answer.push_back(0);
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}
