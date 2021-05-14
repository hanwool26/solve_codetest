#include <iostream>
#include <time.h>
using namespace std;

int map[50][50];
int visit[50][50];
int N;
int answer = 0;

void init_case() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][j] = visit[i][j] = 0;
		}
	}
	answer = N * N;
}

enum direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

void DFS(int x, int y, int dir, int cnt) {
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return;
	int pipe = map[x][y];
	if (pipe == 0) return;

	// printf("(%d,%d) pipe : %d, cnt %d ans : %d\n", x, y, pipe, cnt, answer);
	if (x == N - 1 && y == N - 1 && (pipe == 1 || pipe == 6)) {
		if (answer > cnt) {
			answer = cnt;
		}
		return;
	}
	if (visit[x][y] == 1) return;
	int next_x, next_y;
	visit[x][y] = 1;

	if (pipe <= 2) {
		if (dir == UP) {
			next_x = x - 1;
			next_y = y;
			DFS(next_x, next_y, UP, cnt + 1);
		}
		if (dir == DOWN) {
			next_x = x + 1;
			next_y = y;
			DFS(next_x, next_y, DOWN, cnt + 1);
		}
		if (dir == LEFT) {
			next_x = x;
			next_y = y - 1;
			DFS(next_x, next_y, LEFT, cnt + 1);
		}
		if (dir == RIGHT) {
			next_x = x;
			next_y = y + 1;
			DFS(next_x, next_y, RIGHT, cnt + 1);
		}
	}
	else {
		if (dir == UP || dir == DOWN) {
			next_x = x;
			next_y = y + 1;
			DFS(next_x, next_y, RIGHT, cnt + 1);
			next_y = y - 1;
			DFS(next_x, next_y, LEFT, cnt + 1);
		}
		if (dir == LEFT || dir == RIGHT) {
			next_x = x + 1;
			next_y = y;
			DFS(next_x, next_y, DOWN, cnt + 1);
			next_x = x - 1;
			next_y = y;
			DFS(next_x, next_y, UP, cnt + 1);
		}
	}
	visit[x][y] = 0;
}

int main() {
	int T;
	clock_t start, end;

	start = clock();
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("pipe_connection_input.txt", "r", stdin);
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		init_case();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		DFS(0, 0, RIGHT, 1);
		cout << "#" << tc + 1 << " " << answer << endl;
	}
	end = clock();
	double result = (double)(end - start)/CLOCKS_PER_SEC;
	cout << result << endl;
}
