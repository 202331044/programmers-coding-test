#include <vector>

using namespace std;

int computeTotalScore(const int& size, int& score1, vector<bool> visited, vector<int>& cards)
{
    int result = 0;
    for(int i = 1; i <= size; ++i)
    {
        if(visited[i] == true)
            continue;
        
        visited[i] = true;
        int score2 = 1;
        int next = cards[i - 1];
        
        while(1)
        {
            if(visited[next] == true)
            {
                result = max(result, score1 * score2);
                break;
            }
            
            visited[next] = true;
            next = cards[next-1];
            score2++;
        }
    }
    return result;
}

int solution(vector<int> cards) {
    int answer = 0;
    int size = cards.size();
    vector<bool> visited(size + 1, false);
    
    for(int i = 1; i <= size; ++i)
    {
        if(visited[i] == true)
            continue;
        
        visited[i] = true;
        int next = cards[i - 1];
        int score = 1;

        while(score < size)
        {
            if(visited[next] == false)
            {
                visited[next] = true;
                score++;
                next = cards[next - 1];
            }
            else
            {
               int result = computeTotalScore(size, score, visited, cards);
               answer = max(answer, result);
               break;
            }
        }
    }
    return answer;
}
