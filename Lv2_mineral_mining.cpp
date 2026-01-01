#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int total = 0;
    int size = minerals.size();
    int dia = 0, iron = 0, stone = 0;
    priority_queue<pair<int, tuple<int ,int, int>>> pq;
    
    for(int i = 0; i < 3; ++i)
        total += picks[i];
    total *= 5;
    
    size = size < total ? size : total;
    
    for(int i = 0; i < size; ++i)
    {
        if(minerals[i] == "diamond")
            dia++;            
        else if(minerals[i] == "iron")
            iron++;
        else
            stone++;
        
        if((dia + iron + stone == 5) || (i == size - 1))
        {
            pq.push({dia*25 + iron*5 + stone, {dia, iron, stone}});
            dia = 0;
            iron = 0;
            stone = 0;
        }  
    }
    
    int idx = 0;
    while(!pq.empty())
    {
        auto [num, mineral] = pq.top();
        pq.pop();

        dia = get<0>(mineral);
        iron = get<1>(mineral);
        stone = get<2>(mineral);
        
        while(idx < 3 && picks[idx] <= 0)
            idx++;
        
        if(idx > 2) break;
        
        if(idx == 0)
            answer += dia + iron + stone;
        else if(idx == 1)
            answer += dia * 5 + iron + stone;
        else
            answer += dia * 25 + iron * 5 + stone;
        
         picks[idx]--; 
    }

    return answer;
}
