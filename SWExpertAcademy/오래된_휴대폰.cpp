#include <iostream>
#include <vector>

using namespace std;
int answer;
int N, O, M, W;
int num[10];
bool op[5]; // 1: '+', 2: '-', 3: '*', 4: '/' 

int dp[999];

void init_test() {
	answer = 0;
	memset(dp, 0, sizeof(dp));
	memset(op, false, sizeof(false));
}

void init_dp(int number, int digit) {
	if (number > 999) return;
	if (digit == -1) {
		for (int i = 0; i < N; i++) {
			dp[num[i]] = 1;
			init_dp(num[i], 0);
		}
		return;
	}

	if (dp[number] == 0) dp[number] = digit;
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
	cin >> T;

	for (int tc = 1; tc <= 1; tc++) {
		init_test();
		cin >> N >> O >> M;
		for (int i = 0; i < N; i++) {
			cin >> num[i];		
		}
		for (int i = 0; i < O; i++) {
			op[i] = true;
		}	
		
		cin >> W;
		init_dp(0, -1);
		if (dp[W] != 0) {
			answer = dp[W];
		}
		else {
			continue;
		}
		for (int i = 0; i < 1000; i++) {
			cout << i << " : " << dp[i] << endl;
		}
		cout << "#" << tc << " " << answer << endl;
	}
	return 0;
}
