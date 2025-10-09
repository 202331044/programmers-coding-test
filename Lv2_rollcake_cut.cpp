#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    unordered_set<int> set;
    vector<int> count(10001, 0);
    int cnt = 0, answer = 0;

    for(int i = 0; i < topping.size(); ++i)
    {
        if(count[topping[i]] == 0)
            cnt++;
        count[topping[i]]++;
    }
    
    for(int j = 0; j < topping.size(); ++j)
    {
        set.insert(topping[j]);
        count[topping[j]]--;
      
        if(count[topping[j]] == 0)
            cnt--;
        if(set.size() == cnt)
            answer++;
    }
    return answer;
}
