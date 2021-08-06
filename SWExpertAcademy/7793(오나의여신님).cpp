#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct node {
	int x;
	int y;
	int time;
	node(int a, int b, int c) {
		x = a;
		y = b;
		time = c;
	}
}Node;

char map[50][50];
int R, C;
int answer;

int dir_x[] = { -1,1,0,0 };
int dir_y[] = { 0,0,-1,1 };

queue<Node> q;
bool visit[50][50];

Node S(0,0,0), D(0,0,0);

void BFS() {
	memset(visit, false, sizeof(visit));
	q.push(Node(S.x, S.y, S.time));
	visit[S.x][S.y] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
		q.pop();
		if (x == D.x && y == D.y) {
			answer = min(answer, time);
			//break;
		}
		if (map[x][y] == '*') {
			for (int i = 0; i < 4; i++) {
				int nx = x + dir_x[i];
				int ny = y + dir_y[i];
				if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1 || map[nx][ny] == 'X' || map[nx][ny] == 'S' || map[nx][ny] == 'D' || map[nx][ny] == '*') continue;
				map[nx][ny] = '*';
				q.push(Node(nx, ny, time + 1));
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				int nx = x + dir_x[i];
				int ny = y + dir_y[i];
				if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1 || map[nx][ny] == 'X' || map[nx][ny] == '*' || visit[nx][ny] == true ) continue;
				if (map[nx][ny] == 'D') {
					q.push(Node(nx, ny, time + 1)); continue;
				}
				q.push(Node(nx, ny, time + 1));
				visit[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("8050.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		answer = (int)1e9;
		cin >> R >> C;
		char temp[50];
		for (int i = 0; i < R; i++) {
			cin >> temp;
			for (int j = 0; j < C; j++) {
				map[i][j] = temp[j];
				if (map[i][j] == '*') {
					q.push(Node(i, j, 0));
				}
				else if (map[i][j] == 'S') {
					S.x = i; S.y = j; S.time = 0;
				}
				else if (map[i][j] == 'D') {
					D.x = i; D.y = j; D.time = 0;
				}
			}
		}
		BFS();
		if (answer < (int)1e9)	cout << "#" << tc << " " << answer << endl;
		else cout << "#" << tc << " GAME OVER" << endl;
	}
}
