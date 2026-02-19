#include <string>
#include <vector>

using namespace std;

string friends = "ACFJMNRT";
void make_cases(string str, vector<string>& cases)
{
    if(str.size() == 8)
    {
        cases.push_back(str);
        return;
    }
    
    for(int i = 0; i < 8; ++i)
    {
        if(str.find(friends[i]) == -1)
            make_cases(str + friends[i], cases);
    }  
}

bool isCase(const char op, int& num, int& p1, int& p2)
{
    if(op == '=')
        return (abs(p1-p2) - 1 == num) ? true : false;
    else if(op == '<')
        return (abs(p1-p2) - 1 < num) ? true : false;
    else
        return (abs(p1-p2) - 1 > num) ? true : false;
}

int solution(int n, vector<string> data) {
    const int SIZE = 8*7*6*5*4*3*2*1;
    int answer = SIZE;
    string str;
    
    vector<bool> visited(SIZE, true);
    vector<string> cases;
    make_cases(str, cases);
    
    for(const auto& d: data)
    {
        char f1 = d[0];
        char f2 = d[2];
        char op = d[3];
        int num = d[4] - '0';
        
        for(int i = 0; i < cases.size(); ++i)
        {
            if(visited[i] == false)
                continue;
            
            int p1 = cases[i].find(f1);
            int p2 = cases[i].find(f2);
            
            if(isCase(op, num, p1, p2) == false)
            {
                answer--;
                visited[i] = false;
            }
        }
    }
    return answer;
}
