#include <string>
#include <vector>

using namespace std;

string binary_number(long long number)
{
    string str;
    while(number)
    {
        str += (number % 2) + '0';
        number /= 2;
    }
    
    str += '0';
    return str;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    long long num;
    int cnt;
    
    for(auto number: numbers)
    {
        num = number;
        cnt = 0;
        string str = binary_number(number);

        for(int i = 0; i < str.length(); ++i)
        {
            if(str[i] == '0')
            {
                str[i] = '1';
                cnt++;
                break;
            }
            else
            {
                str[i] = '0';
                cnt++;
            }
        }
        num++;
        
        long long p = 1;
        for(int j = 0; j < str.length(); ++j)
        {
            if(cnt <= 2)
                break;
            
            num += p;
            p *= 2;
            cnt--;
        }
        answer.push_back(num);
    }

    return answer;
}
