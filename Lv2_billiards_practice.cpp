#include <vector>
using namespace std;

int calcDist(int& x, int& y, int& a, int& b)
{
    return (a - x) * (a - x) + (b - y) * (b - y);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(auto ball: balls)
    {
        int minDist = 1000*1000;
        int a = ball[0], b = ball[1];
        int x, y, dist;
        
        if(!(a == startX && startY > b))
        {
            x = startX, y = -startY;
            dist = calcDist(x, y, a, b);
            minDist = minDist > dist ? dist : minDist;
        }
        if(!(a == startX && startY < b))
        {
            x = startX, y = n + (n - startY);
            dist = calcDist(x, y, a, b);
            minDist = minDist > dist ? dist : minDist;
        }
        if(!(b == startY && startX > a))
        {
            x = -startX, y = startY;
            dist = calcDist(x, y, a, b);
            minDist = minDist > dist ? dist : minDist;
        }
        if(!(b == startY && startX < a))
        {
            x = m + (m - startX), y = startY;
            dist = calcDist(x, y, a, b);
            minDist = minDist > dist ? dist : minDist;
        }
        
        answer.push_back(minDist);
    }
    return answer;
}
