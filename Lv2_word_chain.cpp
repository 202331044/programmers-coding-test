#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    for(int i = 1; i < words.size(); ++i)
    {
        auto it = find(words.begin(), words.end(), words[i]);
        int len = words[i-1].length();

        if(it - words.begin() != i || words[i-1][len-1] != words[i][0])
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}
