#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <utility>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string ,string>> vec;
    unordered_map<string, string> umap;
    string state, id, name;
    
    for(auto user: record)
    {
        istringstream iss(user);
        iss >> state;
        
        if(state.compare("Leave") == 0)
            iss >> id;
        else
            iss >> id >> name;
        
        vec.push_back({state, id});
        
        if(state.compare("Leave") != 0)
            umap[id] = name;
    }
    
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        state = it->first;
        id = it->second;

        if(state.compare("Enter") == 0)
            answer.push_back(umap[id] + "님이 들어왔습니다."); 
        else if(state.compare("Leave") == 0)
            answer.push_back(umap[id] + "님이 나갔습니다.");   
    }
    
    return answer;
}
