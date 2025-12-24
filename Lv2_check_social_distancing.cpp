#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int N = 5;
int dr[6] = {1, 0, 2, 0, 1, 1};
int dc[6] = {0, 1, 0, 2, 1, -1};

int isKeepingDistance(int idx, vector<vector<string>>& places)
{
    for(int r = 0; r < N; ++r)
    {
        for(int c = 0; c < N; ++c)
        {
            if(places[idx][r][c] != 'P')
                continue;
            
            for(int choice = 0; choice < 6; ++choice)
            {
                int nr = r + dr[choice];
                int nc = c + dc[choice];
                
                if(nr >= 0 && nr < N && nc >= 0 && nc < N 
                   && places[idx][nr][nc] == 'P')
                {
                    if(choice == 0 || choice == 1)
                        return 0;
                    else if(choice == 2 && places[idx][nr - 1][nc] != 'X')
                        return 0;
                    else if(choice == 3 && places[idx][nr][nc - 1] != 'X')
                        return 0;
                    else if(choice == 4 && (places[idx][nr-1][nc] != 'X' 
                            || places[idx][nr][nc-1] != 'X'))
                        return 0;
                    else if(choice == 5 && (places[idx][nr - 1][nc] != 'X'
                            || places[idx][nr][nc + 1] != 'X'))
                        return 0;
                }   
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int idx = 0; idx < N; ++idx)
        answer.push_back(isKeepingDistance(idx, places));
    return answer;
}
