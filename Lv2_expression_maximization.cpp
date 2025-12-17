#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

void splitStr(string& expression, vector<long long>& numVec, vector<char>& opVec)
{
    string str;
    for(int i = 0; i < expression.size(); ++i)
    {
        if(isdigit(expression[i]))
            str += expression[i];
        else
        {
            numVec.push_back(stoll(str));
            opVec.push_back(expression[i]);
            str = "";
        }
    }

    if(str.size())
        numVec.push_back(stoll(str));
}

void calculate(char op, vector<long long>& numVec, vector<char>& opVec,
                vector<long long>& numVec2, vector<char>& opVec2)
{
    for(int i = 0; i < opVec.size(); ++i)
    {
        if(opVec[i] == op)
        {
            if(numVec2.size() == 0)
            {
                if(op == '*')
                    numVec2.push_back(numVec[i] * numVec[i+1]);
                else if(op == '+')
                    numVec2.push_back(numVec[i] + numVec[i+1]);
                else
                    numVec2.push_back(numVec[i] - numVec[i+1]);
            }
            else
            {
                int size = numVec2.size()-1;
                long long num = numVec2[size];
                
                if(op == '*')
                    numVec2[size] = (num * numVec[i+1]);
                else if(op == '+')
                     numVec2[size] = (num + numVec[i+1]);
                else
                     numVec2[size] = (num - numVec[i+1]);
            }
        }
        else
        {
            if(numVec2.size() == 0)
                numVec2.push_back(numVec[i]);
            numVec2.push_back(numVec[i+1]);
            opVec2.push_back(opVec[i]);
        }
    }
    
    if(numVec2.size() != opVec2.size() + 1)
        numVec2.push_back(numVec[numVec.size()-1]);
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> numVec;
    vector<char> opVec;
    splitStr(expression, numVec, opVec);
    vector<string> opOrder = {"+-*", "+*-", "-+*", "-*+", "*+-", "*-+"};
    
    for(string order: opOrder)
    {
        char op = order[0];
        vector<long long> numVec2;
        vector<char> opVec2;
        calculate(op, numVec, opVec, numVec2, opVec2);
        
        op = order[1];
        vector<long long> numVec3;
        vector<char> opVec3;
        calculate(op, numVec2, opVec2, numVec3, opVec3);
        
        op = order[2];
        vector<long long> numVec4;
        vector<char> opVec4;
        calculate(op, numVec3, opVec3, numVec4, opVec4);
        
        answer = max(answer, llabs(numVec4[0]));
    }
    
    return answer;
}
