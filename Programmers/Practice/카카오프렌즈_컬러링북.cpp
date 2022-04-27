#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct pos{
    int x;
    int y;
    pos(int a, int b){
        x = a;
        y = b;
    }
}Pos;

int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};

bool visit[100][100];

int bfs(int m, int n,int x, int y, int color, vector<vector<int>> picture){
    int cnt = 0;
    queue<Pos> q;
    q.push(Pos(x,y));
    visit[x][y] = true;

    while(!q.empty()){
        Pos temp = q.front();
        q.pop();
        int xx = temp.x;
        int yy = temp.y;
        cnt++;
        for(int i=0; i<4; i++){

            int nx = xx + dir_x[i];
            int ny = yy + dir_y[i];
            if(nx < 0 || ny < 0 || nx > m-1 || ny > n-1) continue;
            if(picture[nx][ny] == color && visit[nx][ny] == false) {
                q.push(Pos(nx,ny));
                visit[nx][ny] = true;
            }
        }        
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);

    // visit 초기화
    memset(visit, false, sizeof(visit));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int color = picture[i][j];
            if(visit[i][j] != true && color > 0){
                number_of_area++;
                max_size_of_one_area = max(max_size_of_one_area, bfs(m,n,i,j,color,picture));
            }
        }
    }
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main(){
    
    int m = 6;
    int n = 4;    
    vector<vector<int>> picture
    {
        {1, 1, 1, 0}, 
        {1, 2, 2, 0}, 
        {1, 0, 0, 1},
        {0, 0, 0, 1}, 
        {0, 0, 0, 3}, 
        {0, 0, 0, 3}
    };
    solution(m,n,picture);
    return 0;
}
