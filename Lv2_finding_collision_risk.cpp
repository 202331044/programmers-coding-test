#include <vector>
#include <unordered_map>

using namespace std;

bool isConflict(const int& t, const int& row, const int& col, vector<vector<unordered_map<int, int>>>& arr)
{
    if(arr[row][col][t] == 1)
    {
        arr[row][col][t]++;
        return true;
    }
    else
        arr[row][col][t]++;
    
    return false;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    vector<vector<unordered_map<int, int>>> arr(101, vector<unordered_map<int, int>>(101));
    
    int x = routes.size();
    int m = routes[0].size();
    int answer = 0;
    
    for(int idx = 0; idx < x; ++idx)
    {
        int t = 0;
        int curr = routes[idx][0] - 1;
        int row = points[curr][0];
        int col = points[curr][1];
        
        if(isConflict(t, row, col, arr))
            answer++;
        t++;
        
        for(int j = 1; j < m; ++j)
        {
            int next = routes[idx][j] - 1;
            int nrow = points[next][0];
            int ncol = points[next][1];
            
            if(row < nrow)
            {
                while(row < nrow)
                {
                    ++row;
                    if(isConflict(t, row, col, arr))
                        answer++;
                    t++;
                }
            }
            else
            {
                while(row > nrow)
                {
                    --row;
                    if(isConflict(t, row, col, arr))
                        answer++;
                    t++;
                }
            }
            
            if(col < ncol)
            {
                while(col < ncol)
                {
                    ++col;
                    if(isConflict(t, row, col, arr))
                        answer++;
                    t++;
                }
            }
            else
            {
                while(col > ncol)
                {
                    --col;
                    if(isConflict(t, row, col, arr))
                        answer++;
                    t++;
                }
            }
        }
    }
    return answer;
}
