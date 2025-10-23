#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    bool include = true;
    int answer = 0, cnt = 0;
    
    for(auto skill_tree: skill_trees)
    {
        cnt = 0;
        include = true;
        for(auto c: skill_tree)
        {
            int idx = skill.find(c);
            if(idx != string::npos)
            {
                if(cnt != idx)
                {
                    include = false;
                    break;
                }
                cnt++;
            }
        }
        
        if(include)
            answer++;
    }
    return answer;
}
