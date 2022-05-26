#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

int stu[30000];

using namespace std;

int N, D, K;
bool used[15];
int answer = 0;

string print_binary(int k) {
	char remain[] = { '0', '1' };
	string str = "";
	int idx;
	while (k > 0) {
		idx = k % 2;
		k = k / 2;
		str = remain[idx] + str;
	}
	return str;
}

bool check_joint(int stu_source, int tea_source) {
	if ((stu_source & tea_source) == stu_source) return true;
	return false;
}

void dfs(int idx, int source, int cnt) {
	if (cnt == K) {
		int s_cnt = 0;
		for (int i = 0; i < N; i++) {
			if (check_joint(stu[i], source)) {
				s_cnt++;
			}
		}
		answer = max(answer, s_cnt);
		return;
	}

	for (int i = idx; i <= D; i++) {
		dfs(i + 1, source | (1 << i), cnt + 1);
	}
}

int main() {
	freopen("최대음식선호.txt", "r", stdin);
	cin >> N >> D >> K;
	int source, sn; // amount of sources
	for (int i = 0; i < N; i++) {
		cin >> sn;
		for (int j = 0; j < sn; j++) {
			cin >> source;
			stu[i] |= (1 << source);
		}
	}
	memset(used, false, sizeof(used));
	memset(dp, false, sizeof(dp));
	dfs(1, 0, 0);
	cout << answer << endl;
}
