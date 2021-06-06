#include <iostream>
#include <queue>
using namespace std;

int L, C, R;
char building[30][30][30];
bool visit[30][30][30];
int answer = int(1e9);
int dir_z[] = { -1, 1, 0, 0, 0, 0 };
int dir_x[] = {  0, 0,-1, 1, 0, 0 };
int dir_y[] = {  0, 0, 0, 0,-1, 1 };

#define x first
#define y second

typedef struct node{
	int x;
	int y;
	int z;
	int depth;
	node(int a, int b, int c, int d){
		x = a;
		y = b;
		z = c;
		depth = d;
	}
}Node;

void print_map(){
	for (int i = 0; i < L; i++){
		for (int j = 0; j < R; j++){
			for (int k = 0; k < C; k++){
				cout << building[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
}

void BFS(Node s, Node e){
    queue<Node> q;
	q.push(s);
	int xx, yy, zz;
	int nx, ny, nz;
	int cur_d;	// depth;
	visit[s.x][s.y][s.z] = true;

	while (!q.empty()){
		Node n = q.front();
		xx = n.x;
		yy = n.y;
		zz = n.z;
		cur_d = n.depth;
		q.pop();
		
		if (building[xx][yy][zz] == 'E'){
			answer = cur_d;
		}
		for (int i = 0; i < 6; i++){
			nx = xx + dir_x[i];
			ny = yy + dir_y[i];
			nz = zz + dir_z[i]; 
			if (nx < 0 || nx > L - 1 || ny < 0 || ny > R - 1 || nz < 0 || nz > C - 1 \
				|| visit[nx][ny][nz] || building[nx][ny][nz] == '#') continue;
			q.push(Node(nx, ny, nz, cur_d + 1));
			visit[nx][ny][nz] = true;
		}		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("6593.txt", "r", stdin);
	while (true){
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		answer = int(1e9);
		Node start(0,0,0,0);
		Node end(0,0,0,0);
		for (int i = 0; i < L; i++){
			for (int j = 0; j < R; j++){
				for (int k = 0; k < C; k++){
					cin >> building[i][j][k];
                    visit[i][j][k] = false;
					if (building[i][j][k] == 'S'){
						start.x = i;
						start.y = j;
						start.z = k;
						start.depth = 0;
					}
				}
			}
		}
		//print_map();
		BFS(start, end);
		if (answer != int(1e9)){
			printf("Escaped in %d minute(s).\n", answer);
		}
		else{
			printf("Trapped!\n");
		}
	}
}
