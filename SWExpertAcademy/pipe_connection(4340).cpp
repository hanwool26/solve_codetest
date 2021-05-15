#include <iostream>
using namespace std;

int map[50][50];
int visit[50][50];
int dp[50][50][4];
int N;
int answer = 0;


void init_case() {
	answer = N * N;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visit[i][j] = 0;
			for (int dir = 0; dir < 4; dir++){
				dp[i][j][dir] = answer;
			}
		}
	}
}	

enum direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

void DFS(int x, int y, int dir, int cnt) {
	int pipe = map[x][y];
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1 || pipe == 0 || visit[x][y] == 1) return;
	if (dp[x][y][dir] < cnt) return;

	if (x == N - 1 && y == N - 1 && ((pipe == 1 && dir == RIGHT) || pipe == 6 && dir == DOWN) && cnt!=1) {
		if (answer > cnt) {
			answer = cnt;
		}
		return;
	}

	if (x == 0 && y == 0 && ((pipe == 1 && dir == LEFT) || pipe == 4 && dir == UP) && cnt!=1) {
		if (answer > cnt) {
			answer = cnt;
		}
		return;
	}

	int next_x, next_y;
	visit[x][y] = 1;
	dp[x][y][dir] = cnt;

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
		int a = answer;
		init_case();
		DFS(N - 1, N - 1, LEFT, 1);
		if (answer > a) answer = a;
		
		cout << "#" << tc + 1 << " " << answer << endl;
	}	
}
