#include <string>

using namespace std;

const int SIZE = 11;

int solution(string dirs) {
    bool visited[SIZE][SIZE][SIZE][SIZE] = {false, };
    int x = 5, y = 5;
    int nx = x, ny = y;
    int answer = 0;
    
    for(int i = 0; i < dirs.length(); ++i)
    {
        if(dirs[i] == 'U')
            ny = y - 1;
        else if(dirs[i] == 'D')
            ny = y + 1;
        else if(dirs[i] == 'R')
            nx = x + 1;
        else
            nx = x - 1;
        
        if(nx < SIZE && nx >= 0 && ny < SIZE && ny >= 0)
        {
            if(visited[x][y][nx][ny] == false)
            {
                visited[x][y][nx][ny] = true;
                visited[nx][ny][x][y] = true;
                answer++;
            }
            
            x = nx;
            y = ny;
        }
        else
        {
            nx = x;
            ny = y;
        }
    }
    return answer;
}
