#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

unordered_set<int> result;

bool prime_number(int num)
{
    if(num <= 1)
        return false;
    
    for(int i = 2; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

void bf(string str, string& numbers, vector<bool>& vec)
{
    if(str.size() > 0)
    {
        int num = stoi(str);
        if(prime_number(num))
            result.insert(num);
    }
    
    if(str.size() >= numbers.size())
        return;
    
    for(int i = 0; i < numbers.size(); ++i)
    {
        if(vec[i])
            continue;
        
        vec[i] = true;
        bf(str + numbers[i], numbers, vec);
        vec[i] = false;
    }
}

int solution(string numbers) {
    string str;
    vector<bool> vec(numbers.size(), false);
    
    bf(str, numbers, vec);
    int answer = result.size();
    
    return answer;
}
