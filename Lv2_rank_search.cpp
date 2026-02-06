#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    static int arr[3][2][2][2][100001];

    for(auto& str: info)
    {
        istringstream iss(str);
        string tmp;
        int lan, job, ex, food, score;
        
        while(getline(iss, tmp, ' '))
        {
            if(tmp == "cpp" || tmp == "java" || tmp == "python")
            {
                if(tmp == "cpp") lan = 0;
                else if(tmp == "java") lan = 1;
                else lan = 2;
            }     
            else if(tmp == "backend" || tmp == "frontend")
            {
                if(tmp == "backend") job = 0;
                else job = 1;
            }
            else if(tmp == "junior" || tmp == "senior")
            {
                if(tmp == "junior") ex = 0;
                else ex = 1;
                continue;
            }
            else if(tmp == "chicken" || tmp == "pizza")
            {
                if(tmp == "chicken") food = 0;
                else food = 1;
                continue;
            }
            else
              score = stoi(tmp);
        }  
        arr[lan][job][ex][food][score]++;
    }
    
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k =0; k < 2; ++k)
                for(int l = 0; l < 2; ++l)
                    for(int m = 1; m < 100001; ++m)
                        arr[i][j][k][l][m] += arr[i][j][k][l][m-1];
    
    for(auto& str: query)
    {
        string tmp;
        istringstream iss(str);
        int lan = -1, job = -1, ex = -1, food = -1, score = -1;
        
        while(getline(iss, tmp, ' '))
        {
            if(tmp == "and" || tmp == "-")
                continue;
            
            if(tmp == "cpp" || tmp == "java" || tmp == "python")
            {
                if(tmp == "cpp") lan = 0;
                else if(tmp == "java") lan = 1;
                else lan = 2;
            }
            else if(tmp == "backend" || tmp == "frontend")
            {
                if(tmp == "backend") job = 0;
                else job = 1;
            }
            else if(tmp == "junior" || tmp == "senior")
            {
                if(tmp == "junior") ex = 0;
                else ex = 1;
            }
            else if(tmp == "chicken" || tmp == "pizza")
            {
                if(tmp == "chicken") food = 0;
                else food = 1;
            }
            else
                score = stoi(tmp);
        }  
        
        int sl, el, sj, ej, se, ee, sf, ef, ss, es = 100000;
        if(lan == -1) sl = 0, el = 3;
        else sl = lan, el = lan + 1;
        
        if(job == -1) sj = 0, ej = 2;
        else sj = job, ej = job + 1;
        
        if(ex == -1) se = 0, ee = 2;
        else se = ex, ee = ex + 1;
        
        if(food == -1) sf = 0, ef = 2;
        else sf = food, ef = food + 1;
        
        if(score != -1) ss = (score  > 0) ? score - 1 : 0;
        else ss = 0;
        
        int result = 0;
        for(int i = sl; i < el; ++i)
            for(int j = sj; j < ej; ++j)
                for(int k = se; k < ee; ++k)
                    for(int l = sf; l < ef; ++l)
                        result += (arr[i][j][k][l][es] - arr[i][j][k][l][ss]);
        
        answer.push_back(result);
    }
    
    return answer;
}
