using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int startTime = h1*3600 + m1*60 + s1;
    int endTime = h2*3600 + m2*60 + s2;
    
    int sNum = startTime*59/3600 + startTime*719/43200 - 1;
    int eNum = endTime*59/3600 + endTime*719/43200 - 1;
    
    if(startTime >= 43200) sNum--;
    if(endTime >= 43200) eNum--;
    
    int answer = eNum - sNum;
    
    if(startTime*59%3600 == 0 || startTime*719%43200 == 0) answer++;
    
    return answer;
}
