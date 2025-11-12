#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    int sr = 0, er = n-1, sc = 0, ec = n-1;
    int cnt = 1;
    
    while(sr <= er && sc <= ec)
    {
        for(int i = sr; i <= er; ++i)
        {
            if(vec[i][sc] != 0)
                continue;
            vec[i][sc] = cnt++;
        }
 
        for(int j = sc; j <= ec; ++j)
        {
            if(vec[er][j] != 0)
                continue;
            vec[er][j] = cnt++;
        }
        
        int t = ec;
        for(int k = er; k >= sr; --k)
        {
            if(vec[k][t] != 0)
            {
                t--;
                continue;
            }                
            vec[k][t--] = cnt++;
        }
        sr++;
        er--;
        sc++;
        ec -= 2;
    }
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            answer.push_back(vec[i][j]);
        }
    }
    
    return answer;
}
