#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M,N,K;

int map[100][100];
int cnt;
int num[100];

typedef struct node{
    int x;
    int y;
    node(int a, int b){
        x = a;
        y = b;
    }
}Node;

int dir_x[] = {-1, 1, 0, 0};
int dir_y[] = {0, 0, -1, 1};

void print_map(){
    for(int i=M-1; i>=0; i--){
        for(int j=0; j<N; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int BFS(int x, int y){
    int area = 0;
    queue<Node> q;
    q.push(Node(x,y));
    int cur_x, cur_y, next_x, next_y;
    map[x][y] = 1;

    while(!q.empty()){
        Node n = q.front();
        cur_x = n.x;
        cur_y = n.y;
        q.pop();
        area++;
        for(int i=0; i<4; i++){
            next_x = cur_x + dir_x[i];
            next_y = cur_y + dir_y[i];
            if(next_x < 0 || next_x > M-1 || next_y < 0 || next_y > N-1 || map[next_x][next_y]!=0) continue;
            q.push(Node(next_x,next_y));
            map[next_x][next_y] = 1;
        }
    }
    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("2583.txt", "r", stdin);

    int l_x, l_y, r_x, r_y;

    
    cin >> M >> N >> K;
    for(int i=0; i<K; i++){
        cin >> l_x >> l_y >> r_x >> r_y;
        for(int i=l_y; i<r_y; i++){
            for(int j=l_x; j<r_x; j++){
                map[i][j] = 2;
            }
        }
    }
    cnt = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 0) num[cnt++] = BFS(i,j);
        }
    }
    sort(num, num+cnt);
    cout << cnt << endl;
    for(int i=0; i<cnt; i++){
        cout << num[i] << " ";
    }
    cout << endl;
}
