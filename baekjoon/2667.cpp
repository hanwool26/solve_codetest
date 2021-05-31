#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int map[25][25];
int area[25];
int visit[25][25];

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };
int N;

typedef struct node {
	int x;
	int y;
	node(int a, int b) {
		x = a;
		y = b;
	}
}Node;

int BFS(int x, int y) {
	int cnt = 0;
	int cur_x, cur_y, next_x, next_y;
	queue<Node> q;
	q.push(Node(x, y));	
	visit[x][y] = true;
	while (!q.empty()) {
		Node n = q.front();
		cur_x = n.x;
		cur_y = n.y;
		q.pop();		
		cnt++;
		//printf("(%d %d) %d\n", cur_x, cur_y, map[cur_x][cur_y]);
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + dir_x[i];
			next_y = cur_y + dir_y[i];
			if (visit[next_x][next_y] == true) continue;
			if (next_x < 0 || next_x > N - 1 || next_y < 0 || next_y > N - 1 || map[next_x][next_y] == 0) continue;
			q.push(Node(next_x, next_y));
			visit[next_x][next_y] = true;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("2667.txt", "r", stdin);
	int temp;
	memset(visit, false, sizeof(visit));

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				area[cnt++] = BFS(i, j);
			}
		}
	}
	sort(area, area + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << area[i] << endl;
	}
	return 0;
}
