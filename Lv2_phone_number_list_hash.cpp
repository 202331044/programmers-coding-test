#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> set(phone_book.begin(), phone_book.end());
    bool answer = true;
    
    for(auto str: phone_book)
    {
        string prefix = "";
        
        for(int i = 0; i < str.length() - 1; ++i)
        {
            prefix += str[i];
            if(set.find(prefix) != set.end())
                return false;
        }
    }
    
    return answer;
}
