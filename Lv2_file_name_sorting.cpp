#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string & a, const string& b)
{
    string headA, headB;
    int i = 0, j = 0;
    
    while(i < a.size() || j < b.size())
    {
        if(i < a.size() && !isdigit(a[i]))
        {
            headA += isalpha(a[i]) ? tolower(a[i]) : a[i];
            i++;
        }
        if(j < b.size() && !isdigit(b[j]))
        {
            headB += isalpha(b[j]) ? tolower(b[j]) : b[j];
            j++;
        }
        if(isdigit(a[i]) && isdigit(b[j]))
            break;
    }
    
    if(headA < headB)
        return true;
    else if(headA > headB)
        return false;
    
    string numA, numB;
    while(i < a.size() || j < b.size())
    {
        if(i < a.size() && isdigit(a[i]))
            numA += a[i++];
        if(j < b.size() && isdigit(b[j]))
            numB += b[j++];
        if(!isdigit(a[i]) && !isdigit(b[j]))
            break;
    }
    
    return stoi(numA) < stoi(numB);
}

vector<string> solution(vector<string> files) {
    
    stable_sort(files.begin(), files.end(), cmp);
    return files;
}
