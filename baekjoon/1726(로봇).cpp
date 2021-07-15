#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define MAX 101

int map[101][101];
int visit[101][101][5];
int M, N;

int dir_x[] = { 0, 0, 0, 1, -1 };
int dir_y[] = { 0, 1, -1, 0, 0 };

typedef struct node{
	int x;
	int y;
	int dir;
	int depth;
	node(int a, int b, int c, int d){
		x = a;
		y = b;
		dir = c;
		depth = d;
	}
}Node;


// 1 : 동, 2 : 서, 3 : 남, 4 : 북

int BFS(Node s, Node e){
	int answer = 0;
	queue<Node> q;
	q.push(Node(s.x, s.y, s.dir, s.depth));

	visit[s.x][s.y][s.dir] = true;

	while (!q.empty()){
		Node temp = q.front();
		q.pop();

		int xx = temp.x;
		int yy = temp.y;
		int dir = temp.dir;
		int depth = temp.depth;

		if (xx == e.x && yy == e.y && dir == e.dir){
			answer = depth;
			break;
		}
		// go 
		for (int i = 1; i <= 3; i++){
			int nx = xx + dir_x[dir] * i;
			int ny = yy + dir_y[dir] * i;
			if (nx < 1 || nx > M || ny < 1 || ny > N || map[nx][ny] == 1) break;
			if (visit[nx][ny][dir]) continue;
			q.push(Node(nx, ny, dir, depth + 1));
			visit[nx][ny][dir] = true;
		}

		// turn left or right
		if (dir == 1 || dir == 2){
			if (visit[xx][yy][3] == false){
				q.push(Node(xx, yy, 3, depth + 1));
				visit[xx][yy][3] = true;
			}
			if (visit[xx][yy][4] == false){
				q.push(Node(xx, yy, 4, depth + 1));
				visit[xx][yy][4] = true;
			}

		}
		if (dir == 3 || dir == 4){
			if (visit[xx][yy][1] == false){
				q.push(Node(xx, yy, 1, depth + 1));
				visit[xx][yy][1] = true;
			}
			if (visit[xx][yy][2] == false){
				q.push(Node(xx, yy, 2, depth + 1));
				visit[xx][yy][2] = true;
			}
		}
	}
	return answer;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("1726.txt", "r", stdin);
	memset(visit, false, sizeof(visit));
	cin >> M >> N;
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= N; j++){
			cin >> map[i][j];
		}
	}
	
	int x, y, dir, depth = 0;
	cin >> x >> y >> dir;
	Node s(x, y, dir, depth);
	cin >> x >> y >> dir;
	Node e(x, y, dir, depth);
	
	cout << BFS(s, e) << endl;	
}
