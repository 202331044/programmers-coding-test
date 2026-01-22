#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    vector<int> ckeys;
    
    for(int key = 1; key < (1 << col); ++key)
    {
        bool isInclude = false;
        for(auto ckey: ckeys)
        {
            if((key & ckey) == ckey)
            {
                isInclude = true;
                break;
            }
        }
        
        if(isInclude)
            continue;
            
        bool isCkey = true;
        unordered_set<string> s;
        
        for(int r = 0; r < row; ++r)
        {
            string id;
            for(int c = 0; c < col; ++c)
            {
                if(key & (1 << c))
                    id += relation[r][c] + " ";
            }

            if(!s.insert(id).second)
            {
                isCkey = false;
                break;
            }
        }
        
        if(isCkey)
            ckeys.push_back(key);
    }
    
    return ckeys.size();
}
