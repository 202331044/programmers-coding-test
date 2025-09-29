#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int row, col, num;
    
    for(long long i = left; i <= right; ++i)
    {
        row = i / n + 1;
        col = i % n + 1;
        num = row > col ? row : col;
        answer.push_back(num);
    }

    return answer;
}
