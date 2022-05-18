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
	}
	return 0;
}
