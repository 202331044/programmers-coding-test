#include <string>

using namespace std;

int answer = 0;
int cnt = 0;

void bruteForce(string cmp, string word)
{
    if(cmp.compare(word) == 0)
    {
        answer = cnt;
        return;
    }
    
    if(answer == 0 && cmp.length() <= 5)
    {
        cnt++;
        bruteForce(cmp + 'A', word);
        bruteForce(cmp + 'E', word);
        bruteForce(cmp + 'I', word);
        bruteForce(cmp + 'O', word);
        bruteForce(cmp + 'U', word);
    }
}

int solution(string word) {
    bruteForce("", word);
    return answer;
}
