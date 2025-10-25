#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <utility>
#include <cmath>

using namespace std;

int getTime(int ih, int im, int oh, int om)
{
    int time = 0;
    if(om - im < 0)
    {
        ih++;
        time += (om - im) + 60;
    }
    else
        time += (om - im);
    time += (oh - ih) * 60;
    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, pair<int ,int>> m;
    map<string, int> res;
    string time, number, state;
    int oh, om, ih, im;
    
    for(int i = 0; i < records.size(); ++i)
    {
        istringstream iss(records[i]);
        iss >> time >> number >> state;
        
        if(m.find(number) == m.end())
            m[number] = {stoi(time.substr(0, 2)), stoi(time.substr(3, 2))};
        else
        {
            oh = stoi(time.substr(0,2));
            om = stoi(time.substr(3, 2));
            ih = m[number].first;
            im = m[number].second;
            res[number] += getTime(ih, im, oh, om);;
            m.erase(number);
        }
    }   
    
    oh = 23;
    om = 59;
    for(auto it = m.begin(); it != m.end(); ++it)
    {
        ih = it->second.first;
        im = it->second.second;
        res[it->first] += getTime(ih, im, oh, om);
    }
    
    for(auto it = res.begin(); it != res.end(); ++it)
    {
        int t = it->second;
        if(t <= fees[0])
            answer.push_back(fees[1]);
        else
            answer.push_back(fees[1] + ceil(float(t - fees[0])/fees[2]) * fees[3]);
    }
    return answer;
}
