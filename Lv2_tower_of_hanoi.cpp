#include <vector>

using namespace std;

void hanoiTower(vector<vector<int>>& answer, const int& from, const int& tmp, const int& to, int idx)
{
    if(idx == 0)
        return;
    hanoiTower(answer, from, to, tmp, idx-1);
    answer.push_back({from, to});
    hanoiTower(answer, tmp, from, to, idx-1);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoiTower(answer, 1, 2, 3, n);
    return answer;
}
