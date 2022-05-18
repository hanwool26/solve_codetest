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
	memset(dp, 0, sizeof(dp));
	memset(op, false, sizeof(false));
}

void dfs(int number, int touch, int flag) {
	if (number < 0 || number > 999 || touch+flag> M || answer < touch+flag) {
		return;
	}
	if (number == W) {
		answer = touch + flag;
		return;
	}

	if (dp[number] == 0 || dp[number] > touch + flag) {
		dp[number] = touch + flag;
	}
	
	for (int i = 0; i < 1000; i++) {

		if (i == 5) cout << dp[number] << endl;
			for (int j = 1; j < 5; j++) {
				if (op[j] == true) {
					int temp = -1;
					if (j == 1) temp = number + i;
					else if (j == 2) temp = number - i;
					else if (j == 3) temp = number * i;
					else if (j == 4 && i != 0) temp = number / i;
					if (temp!=-1)
						dfs(number, dp[number]+dp[i],1);
				}
			}
		}
	
}

void init_dp(int number, int digit) {
	if (number > 999) return;
	if (digit == -1) {
		for (int i = 0; i < N; i++) {
			origin[num[i]] = dp[num[i]] = 1;
			init_dp(num[i], 0);
		}
		return;
	}
	if (dp[number] == 0) origin[number] = dp[number] = digit;
	else if(dp[number] != 0 && digit>0)
		return;
	
	for (int i = 0; i < N; i++) {
		init_dp(number * 10 + num[i], digit + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("old_phone.txt", "r", stdin);
	int T;
	int op_idx;
	cin >> T;

	for (int tc = 1; tc <= 1; tc++) {
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
		cout << W << endl;
		init_dp(0, -1);
		if (dp[W] > 0) {
			answer = dp[W];
		}
		else {
			for (int i = 0; i < 1000; i++) {
				if (dp[i] && origin[i])
					dfs(i, dp[i],0);
			}		
			answer = dp[W];
		}
		
		for (int i = 0; i < 1000; i++) {
			cout << i << " : " << dp[i] << endl;
		}
		
		
		cout << "#" << tc << " " << answer << endl;
	}
	return 0;
}
