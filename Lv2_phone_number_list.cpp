#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    bool answer = true;
    
    for(int i = 0; i < phone_book.size() - 1; ++i)
    {
        for(int j = 0; j < phone_book[i].length(); ++j)
        {
            if(phone_book[i][j] != phone_book[i+1][j])
            {
                answer = true;
                break;
            }
            else
                answer = false;
        }
        if(answer == false)
            return answer;
    }
    return answer;
}
