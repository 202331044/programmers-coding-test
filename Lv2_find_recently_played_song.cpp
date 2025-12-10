#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <functional>

using namespace std;
using iis = tuple<int, int, string>;

void strTransfer(string& str)
{
     while(1)
    {
        size_t pos = str.find("#");
        if(pos == string::npos)
            break;
         
        pos--;
        string r = "";
        r += (str[pos] + 7);
        str.replace(pos, 2, r);
    }
}

int getTime(string& start, string& end)
{
    int time = stoi(end.substr(0, 2)) - stoi(start.substr(0, 2));
    time *= 60;
    time += stoi(end.substr(3, 2)) - stoi(start.substr(3, 2));
    return time;
}

string makeInfos(int time, string& str)
{
    string result = "";
    for(int i = 0; i < time; ++i)
        result += str[i % str.size()];
    
    return result;
}

string solution(string m, vector<string> musicinfos) {
   
    string token;
    strTransfer(m);
    vector<iis> vec;
    int num = 100;
    
    for(auto music: musicinfos)
    {
        istringstream iss(music);
        vector<string> tmp(4);
        int cnt = 0;
        
        while(getline(iss, token, ','))
            tmp[cnt++] = token;
        
        string start = tmp[0];
        string end = tmp[1];
        string title = tmp[2];
        string info = tmp[3];
        
        int time = getTime(start, end);
        strTransfer(info);
        string infos = makeInfos(time, info);
        
        int idx1 = 0, idx2 = 0;
        size_t n = infos.find(m);
        if(n != string::npos)
            vec.push_back({time, num--, title});
    }
    
    string answer = "(None)";
    if(vec.size() != 0)
    {
        sort(vec.begin(), vec.end(), greater<iis>());
        answer = get<2>(vec[0]);
    }
    
    return answer;
}
