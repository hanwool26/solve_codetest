#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char map[20][20];
int C, R;

typedef struct node{
    int x;
    int y;
    int depth;
    node(int a, int b, int c){
        x = a;
        y = b;
        depth =c;
    }
}Node;

typedef struct edge{
    int adj;
    int dis;
    edge(int a, int b){
        adj = a;
        dis =b;
    }
    bool operator<(const edge &b)const{
        return dis > b.dis;
    }
}Edge;

Node start(Node(0,0,0));
vector<Node> dv; // dirty vector
int dir_x[] = {-1,1,0,0};
int dir_y[] = {0,0,-1,1};

int graph[20][20];
vector<Edge> de[10];

void print_graph(){
    for(int i =0; i<de[0].size(); i++){
        for(int j=0; j<de[0].size(); j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void make_graph(){
    queue<Node> q;    
    int visit[20][20];
    for(int i =0; i<dv.size(); i++){
        memset(visit, false, sizeof(visit));
        q.push(Node(dv[i].x, dv[i].y, dv[i].depth));

    while(!q.empty()){
        Node temp = q.front();
        q.pop();
        int x = temp.x;
        int y = temp.y;
        int depth = temp.depth;
        for(int k=0; k<dv.size(); k++){
            if (x == dv[k].x && y == dv[k].y){
                de[k].push_back(Edge(i,depth));
                de[i].push_back(Edge(k,depth));
                graph[i][k] = graph[k][i] = depth;
            }
        }
        for(int i=0; i<dv.size(); i++){
            int nx = x + dir_x[i];
            int ny = y + dir_y[i];
            if(nx < 0 || nx > R-1 || ny < 0 || ny > C-1 || visit[nx][ny] || map[nx][ny] == 'x') continue;
            q.push(Node(nx,ny, depth+1));
            visit[nx][ny] = true;
        }
    }
    }
  
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true){
        cin >> C >> R;
        if(C==0 && R==0) break;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin >> map[i][j];
                if(map[i][j] == 'o'){
                    start.x = i;
                    start.y = j;
                }
                if(map[i][j] == '*' || map[i][j] == '0'){
                    dv.push_back(Node(i,j,0));
                }
            }
        }
        make_graph();
        print_graph();

    }
    
}
