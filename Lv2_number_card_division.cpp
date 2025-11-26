#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <functional>

using namespace std;

void getDivisors(int& num, set<int, greater<int>>& s)
{
    for(int i = 1; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
        {
            s.insert(i);
            s.insert(num / i);
        }         
    }
}

void getCommonDivisors(set<int, greater<int>>& s, vector<int>& vec, 
                       set<int, greater<int>>& res)
{
    bool check;
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        check = true;
        for(int i = 0; i < vec.size(); ++i)
        {
            if(vec[i] % *it != 0)
            {
                check = false;
                break;
            }            
        }
        
        if(check)
            res.insert(*it);        
    }
}

int getExclusiveDivisors(set<int, greater<int>>& s, vector<int>& vec)
{
    bool check;
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        check = true;
        for(int i = 0; i < vec.size(); ++i)
        {
            if(vec[i] % *it == 0)
            {
                check = false;
                break;
            }        
        }
        
        if(check)
            return *it;
    }
    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    set<int, greater<int>> setA, setB, resA, resB;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    getDivisors(arrayA[0], setA);
    getCommonDivisors(setA, arrayA, resA);
    if(!resA.empty())
        answer = getExclusiveDivisors(resA, arrayB);
    
    getDivisors(arrayB[0], setB);
    getCommonDivisors(setB, arrayB, resB);
    if(!resB.empty())
        answer = max(getExclusiveDivisors(resB, arrayA), answer);

    return answer;
}
