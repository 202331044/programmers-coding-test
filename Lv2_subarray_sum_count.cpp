#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    
    unordered_set<int> s;
    int size = 1, start = 0, sum = 0;
    
    while(size <= elements.size())
    {
        sum = 0;
        start = 0;
        
        for(int i = 0; i < size; ++i)
            sum += elements[i];
        
        s.insert(sum);
        
        while(start < elements.size() - 1)
        {
            sum -= elements[start];
            sum += elements[(start + size) % (elements.size())];
            s.insert(sum);
            start++;
        }
        size++;
    }
    
    int answer = s.size();
    
    return answer;
}
