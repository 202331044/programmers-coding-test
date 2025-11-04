#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    queue<int> que1, que2;
    int size = 3* queue1.size();
    int answer = 0;
    long long sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < queue1.size(); ++i)
    {
        que1.push(queue1[i]);
        que2.push(queue2[i]);
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    while(!que1.empty() && !que2.empty() && answer <= size)
    {
        if(sum1 == sum2)
            break;
        else if(sum1 < sum2)
        {
            int num = que2.front();
            que2.pop();
            que1.push(num);
            sum1 += num;
            sum2 -= num;
            answer++;
        }
        else
        {
            int num = que1.front();
            que1.pop();
            que2.push(num);
            sum1 -= num;
            sum2 += num;
            answer++;
        }
    }
    
    if(sum1 != sum2)
        answer = -1;
    
    return answer;
}
