#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int map[50][50];
int visit[50][50];
int dp[50][50][4];
int answer;

void init_test() {	
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			visit[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	
}
/* Pipe : */
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3
/*
dir : Input 방향
*/
void dfs(int x, int y, int dir, int cnt) {
	
	if (x < 0 || y < 0 || x > N - 1 || y > N - 1 || visit[x][y]) return;
	int cur_pipe = map[x][y];
	if (cur_pipe == 0) return;

	if (x == N - 1 && y == N - 1 && 
		((dir == RIGHT && cur_pipe <= 2 ) || (dir == DOWN && cur_pipe > 2))) {
		if (answer > cnt) answer = cnt;
		return; 
	}
	
	if (dp[x][y][dir] == 0) dp[x][y][dir] = cnt;
	else {
		if (dp[x][y][dir] > cnt) dp[x][y][dir] = cnt;
		else return;
	}
	visit[x][y] = true;

	if (dir == LEFT || dir == RIGHT)
	{		
		if (cur_pipe > 2) {
			dfs(x - 1, y, UP, cnt + 1);
			dfs(x + 1, y, DOWN, cnt + 1);
		}
		else {
			dfs(x, y - 1, LEFT, cnt + 1);
			dfs(x, y + 1, RIGHT, cnt + 1);
		}
	}
	if (dir == UP || dir == DOWN) {
		if (cur_pipe > 2) { 
			dfs(x, y - 1, LEFT, cnt + 1);
			dfs(x, y + 1, RIGHT, cnt + 1);
		}
		else {
			dfs(x-1, y, UP, cnt + 1);	
			dfs(x + 1, y, DOWN, cnt + 1);
		}
	}
	visit[x][y] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("pipe.txt", "r", stdin);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		init_test();
		answer = 1e9;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		dfs(0, 0, RIGHT, 1);
		init_test();
		dfs(N - 1, N - 1, LEFT, 1);

		cout << "#" << tc << " " << answer << endl;
	}
}
