#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
using ll = long long;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<ll, ll>> pos;
    
    for(int i = 0; i < line.size()-1; ++i)
    {
        ll a = line[i][0], b = line[i][1], e = line[i][2];
        for(int j = i + 1; j < line.size(); ++j)
        {
            ll c = line[j][0], d = line[j][1], f = line[j][2];
            ll det = a*d - b*c;
            
            if(det == 0)
                continue;
            
            ll x = b*f - e*d, y = e*c - a*f;
            if(x % det == 0 && y % det == 0)
                pos.emplace_back(x / det, y / det);
        }
    }
    
    ll maxX = pos[0].first, minX = pos[0].first;
    ll maxY = pos[0].second, minY = pos[0].second;
    
    for(int i = 0; i < pos.size(); ++i)
    {
        maxX = max(pos[i].first, maxX);
        minX = min(pos[i].first, minX);
        maxY = max(pos[i].second, maxY);
        minY = min(pos[i].second, minY);
    }
    
    int width = maxX - minX + 1;
    int height = maxY - minY + 1;
    
    vector<string> answer(height, string(width, '.'));
    
    for(auto& [x, y]: pos)
    {
        int nx = x - minX;
        int ny = maxY - y;
        answer[ny][nx] = '*';
    }
    
    return answer;
}
