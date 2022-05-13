#include <iostream>
#include <time.h>

using namespace std;

int waper[10][25];
int N, M;
int ans;

int dp[(1<<10)][25];

bool is_empty_(int x, int y) {
	if (waper[x][y] == 0 && waper[x + 1][y] == 0 && waper[x][y + 1] == 0 && waper[x + 1][y + 1] == 0)
		return true;
	else
		return false;
}

void set_empty(int x, int y, bool set) {
	if (set == true) {
		waper[x][y] = waper[x + 1][y] = waper[x][y + 1] = waper[x + 1][y + 1] = 1;
	}
	else if (set == false) {
		waper[x][y] = waper[x + 1][y] = waper[x][y + 1] = waper[x + 1][y + 1] = 0;
	}
}

void print_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << waper[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------" << endl;
}

int bit_save;

void DFS(int x, int y, int bit, int cnt) {
	if (x > N || y > M) return;

	if (x > N-1) {
		x = 0;
		y = y + 1;
		bit_save = bit;
		bit = 0;
	}
	if (y == M-1) {
		ans = max(ans, cnt);		
		return;
	}	

	if (x == 0) {
		if (dp[bit_save][y] < cnt) {
			dp[bit_save][y] = cnt;
		}
		else {
			return;
		}
	}	

	if (is_empty_(x, y) && x < N-1 && y < M-1) {
		set_empty(x, y, true);
		DFS(x+2, y, bit|(1<<x), cnt + 1);		
		set_empty(x, y, false);
	}
	DFS(x+1, y, bit, cnt);
}

void init_test() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			waper[i][j] = -1;
		}
	}
	for (int i = 0; i < (1<<N); i++) {
		for (int j = 0; j < M; j++) {
			dp[i][j] = -1;
		}
	}
	ans = 0;
}

int main() {
	clock_t s, e;
	s = clock();
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("chip_production.txt", "r", stdin);
	int TC; cin >> TC;

	for (int tc = 1; tc <= TC; tc++) {
		
		cin >> N >> M;
		init_test();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> waper[i][j];
			}
		}
		DFS(0, 0, 0,0);
		cout << "#" << tc << " " << ans << endl;
	}
	e = clock();
	cout << "time : " << (double)(e - s) / CLOCKS_PER_SEC << endl;
	return 0;
}
