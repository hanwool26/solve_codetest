#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
pair<int, int> start;
pair<int, int> finish;
int map[100][100];
int visit[100][100];

enum {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

typedef struct node {
	int x;
	int y;
	int dir;
	int dir_cnt;
	node(int x, int y, int dir, int dir_cnt) {
		this->x = x;
		this->y = y;
		this->dir = dir;
		this->dir_cnt = dir_cnt;
	}
}Node;

int answer = 1e9;


void bfs(int x, int y) {
	queue<Node> q;
	q.push(Node(x, y, -1, 0));
	visit[x][y] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dir = q.front().dir;
		int dir_cnt = q.front().dir_cnt;
	
		q.pop();
		if (x == finish.first && y == finish.second) {
			answer = min(answer, dir_cnt);
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N || ((i != dir) && (visit[nx][ny] < dir_cnt + 1)) || ((i == dir) && (visit[nx][ny] < dir_cnt)) ||
				map[nx][ny] == 1) continue;

			if (dir != i) { // 방향이 다르면
				q.push(Node(nx, ny, i, dir_cnt + 1));
				visit[nx][ny] = dir_cnt+1;
			}
			else { // 방향이 같으면
				q.push(Node(nx, ny, i, dir_cnt));
				visit[nx][ny] = dir_cnt;
			}			
		}
	}
}

int main() {
	freopen("톰과제리.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	int x, y;
	cin >> x >> y;
	start = { x, y };
	cin >> x >> y;
	finish = { x, y };
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			visit[i][j] = 1e9;
		}
	}
	bfs(start.first, start.second);
	cout << ((answer==1e9)?-1:answer-1) << endl;
	return 0;
}
