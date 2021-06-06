#include <iostream>
#include <queue>
using namespace std;

int R, C;
int map[101][101];
bool visit[101][101] = { false, };

int dir_x[] = { 0, 0, 1, -1 };
int dir_y[] = { 1, -1, 0, 0 };	// E W S N

typedef struct node{
	int x;
	int y;
	int dir;
	int cnt;
	node(int a, int b, int c, int d){
		x = a;
		y = b;
		dir = c;
		cnt = d;
	}
}Node;
Node s(0,0,0,0), e(0,0,0,0);

enum dir{
	E = 1,
	W,
	S,
	N
};

int answer = 0;

void print_map(){
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS(Node n){
	queue<Node> q;
	int xx, yy, nx, ny;
	int cur_dir, next_dir;
	int cnt;
	q.push(Node(s.x, s.y, s.dir, s.cnt));

	while (!q.empty()){
		Node n = q.front();
		xx = n.x;
		yy = n.y;
		cur_dir = n.dir;
		cnt = n.cnt;
		q.pop();
		visit[xx][yy] = true;
		if (e.x == xx && e.y == yy){
			if (e.dir != cur_dir) answer = cnt + 1;
			else answer = cnt;
			break;
		}
		 
		for (int i = 0; i < 4; i++){
			nx = xx + dir_x[i];
			ny = yy + dir_y[i];
			if (nx < 1 || nx > R || ny < 1 || ny > C || map[nx][ny] || visit[nx][ny]) continue;
			if (cur_dir != i){
				q.push(node(nx, ny, i, cnt + 2));
			}
			else{
				q.push(node(nx, ny, i, cnt));
			}
		}		
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y, dir;

	freopen("1726.txt", "r", stdin);
	cin >> R >> C;
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cin >> map[i][j];
		}
	}
	cin >> s.x >> s.y >> s.dir;
	cin >> e.x >> e.y >> e.dir;

	//print_map();

	BFS(s);
	cout << answer << endl;

	return 0;
}
