#include <string>
#include <vector>

using namespace std;
const int N = 5;
int dr1[2] = {1, 0};
int dc1[2] = {0, 1};

int dr2[2] = {2, 0};
int dc2[2] = {0, 2};

int dr3[2] = {1, 1};
int dc3[2] = {1, -1};

int checkPlace(const vector<string>& place)
{
    int nr, nc;
    for(int r = 0; r < N; ++r)
    {
        for(int c = 0; c < N; ++c)
        {
            if(place[r][c] != 'P')
                continue;
            
            for(int i = 0; i < 2; ++i)
            {
                nr = r + dr1[i];
                nc = c + dc1[i];
                
                if(nr >= 0 && nr < N && nc >= 0 && nc < N 
                   && place[nr][nc] == 'P')
                    return 0;
            }
            
            for(int i = 0; i < 2; ++i)
            {
                nr = r + dr2[i];
                nc = c + dc2[i];
                
                if(nr >= 0 && nr < N && nc >= 0 && nc < N 
                   && place[nr][nc] == 'P'
                  && place[(r + nr)/2][(c + nc)/2] != 'X')
                        return 0;
            }
            
            for(int i = 0; i < 2; ++i)
            {
                nr = r + dr3[i];
                nc = c + dc3[i];
                
                if(nr >= 0 && nr < N && nc >= 0 && nc < N 
                   && place[nr][nc] == 'P'
                  &&(place[r][nc] != 'X' || place[nr][c] != 'X'))   
                        return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(const auto& place : places)
        answer.push_back(checkPlace(place));
    return answer;
}
