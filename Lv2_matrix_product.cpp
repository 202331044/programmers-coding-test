#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int row1 = arr1.size();
    int size = arr1[0].size();
    int col2 = arr2[0].size();
    vector<vector<int>> answer;
    
    for(int r1 = 0; r1 < row1; ++ r1)
    {   
        vector<int> tmp;
        for(int c2 = 0; c2 < col2; ++c2)
        { 
            int sum = 0;
            for(int p = 0; p < size; ++p)
            {           
                sum+= arr1[r1][p] * arr2[p][c2];
            }
            tmp.push_back(sum);
        }
        answer.push_back(tmp);
    }
    
    return answer;
}
