#include <vector>

using namespace std;

int answer = 0;

void bp(int curr_fatigue, int size, int cnt, vector<vector<int>>& dungeons, vector<bool>& visited)
{
    if(answer < cnt)
        answer = cnt;
    
    for(int i = 0; i < size; ++i)
    {
        if(visited[i] == false && curr_fatigue >= dungeons[i][0])
        {
            visited[i] = true;
            bp(curr_fatigue - dungeons[i][1], size, cnt + 1, dungeons, visited);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int cnt = 0;
    vector<bool> visited(8, false);
    
    bp(k, dungeons.size(), cnt, dungeons, visited);
   
    return answer;
}
