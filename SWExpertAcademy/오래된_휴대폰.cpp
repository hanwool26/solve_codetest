#include <iostream>

using namespace std;
int answer;
int N, O, M, W;
int num[10];
bool op[5]; // 1: '+', 2: '-', 3: '*', 4: '/' 

int dp[1000];
int origin[1000];

void init_test() {
	answer = 21;
	for (int i = 0; i < 1000; i++) {
		origin[i] = dp[i] = 0;
	}
	for (int i = 0; i < 5; i++) {
		op[i] = false;
	}
}

void dfs(int number, int touch, int flag) {
	if (touch + flag > M || touch + flag > answer) {
		return;
	}
	if (number == W) {
		answer = touch + flag;
		return;
	}

	for (int i = 0; i < 1000; i++) {
		if (origin[i] != 0) {
			for (int j = 1; j < 5; j++) {
				if (op[j] == true) {
					if (i == 0 && j == 4) continue;
					int temp;
					if (j == 1) temp = number + i;
					else if (j == 2) temp = number - i;
					else if (j == 3) temp = number * i;
					else if (j == 4) temp = number / i;
					if (temp < 0 || temp > 999) continue;
					if (dp[temp] == 0 || dp[temp] > touch + dp[i] + 1) {
						dp[temp] = touch + dp[i] + 1;
						dfs(temp, dp[temp], 1);
					}
				}
			}
		}
	}
}

void init_dp(int number, int digit) {
	if (number > 999 || digit > 3) return;
	if (digit == -1) {
		for (int i = 0; i < N; i++) {
			origin[num[i]] = dp[num[i]] = 1;
			init_dp(num[i], 1);
		}
		return;
	}
	if (dp[number] == 0) origin[number] = dp[number] = digit;
	else if (dp[number] > digit) origin[number] = dp[number] = digit;

	for (int i = 0; i < N; i++) {
		init_dp(number * 10 + num[i], digit + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("old_phone.txt", "r", stdin);
	int T;
	int op_idx;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init_test();
		cin >> N >> O >> M;
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		for (int i = 0; i < O; i++) {
			cin >> op_idx;
			op[op_idx] = true;
		}

		cin >> W;
		init_dp(0, -1);
		if (dp[W] > 0) {
			answer = dp[W];
		}
		else {
			for (int i = 0; i < 1000; i++) {
				if (origin[i])
					dfs(i, origin[i], 0);
			}
		}
		cout << "#" << tc << " " << (answer == 21 ? -1 : answer) << endl;
	}
	return 0;
}
