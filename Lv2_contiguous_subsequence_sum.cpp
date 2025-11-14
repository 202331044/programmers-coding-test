#include <vector>
#include <utility>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>> pq;
    int sum = 0, l = 0;
    
    for(int i = 0; i < sequence.size(); ++i)
    {
        sum += sequence[i];
        
        while(sum > k)
            sum -= sequence[l++];
        
        if(sum == k)
            pq.push({i - l, l});
    }
    
    int len = pq.top().first;
    int s = pq.top().second;
    pq.pop();
    
    while(!pq.empty())
    {
        if(len == pq.top().first && s > pq.top().second)
        {
            len = pq.top().first;
            s = pq.top().second;
            pq.pop();
        }
        else
            break;      
    }
    
    answer.push_back(s);
    answer.push_back(s + len);
    
    return answer;
}
