#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int f1, f2;
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq(scoville.begin(), scoville.end());
    
    while(pq.size() > 1)
    {
        f1 = pq.top();
        pq.pop();
        if(f1 >= K)
            break;

        f2 = pq.top();
        pq.pop();

        if(f1 > f2)
            swap(f1, f2);
        pq.push(f1 + (f2 * 2));

        answer++;
    }
    
    f1 = pq.top();
    if(f1 < K) answer = -1;
    
    return answer;
}
