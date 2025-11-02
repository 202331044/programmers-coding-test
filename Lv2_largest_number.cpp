#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string & a, const string & b)
{
    string str1 = a + b;
    string str2 = b + a;

    return str1 > str2;
}

string solution(vector<int> numbers) {
    vector<string> str_numbers;
    string answer = "";
    
    for(auto num: numbers)
        str_numbers.push_back(to_string(num));
    
    sort(str_numbers.begin(), str_numbers.end(), cmp);
    for(auto str: str_numbers)
        answer += str;
    
    if(answer[0] == '0')
        answer = '0';

    return answer;
}
