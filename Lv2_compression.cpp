#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    int cnt = 1, pos = 0;
    vector<int> answer;
    unordered_map<string, int> map;
    
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < alphabet.length(); ++i)
         map[string(1, alphabet[i])] = cnt++;
       
    while(pos < msg.length())
    {
        string str;
        while(1)
        {
            if(map.find(str + msg[pos]) != map.end())
            {
                str += msg[pos];
                pos++;
            }                
            else
            {
                answer.push_back(map[str]);
                map[str + msg[pos]] = cnt++;
                break; 
            }    
        }  
    }

    return answer;
}
