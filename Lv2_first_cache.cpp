#include <string>
#include <vector>
#include <cctype>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    list<string> cache;
    int answer = 0;
    
     for(auto city: cities)
     {
         transform(city.begin(), city.end(), city.begin(), 
                   [](unsigned char c) { return tolower(c); });       
         auto it = find(cache.begin(), cache.end(), city);

         if(it!= cache.end())
         {
             answer++; 
             cache.erase(it);
             cache.push_front(city);
             if(cache.size() > cacheSize)
                 cache.pop_back();  
         }
         else
         {
             answer += 5;
             cache.push_front(city);
             if(cache.size() > cacheSize)
                 cache.pop_back();
         }
    }
    
    return answer;
}
