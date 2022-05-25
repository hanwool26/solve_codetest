#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int N, M, R;
typedef struct study {
	int start;
	int finish;
	int effect;
	study(int start, int finish, int effect) {
		this->start = start;
		this->finish = finish;
		this->effect = effect;
	}
	bool operator<(const study& b)const {
		return this->start < b.start;
	}
}Study;

int dp[1000];
int main() {

	freopen("효율적인공부.txt", "r", stdin);
	vector<Study> v;
	stack<int> stack;
	int s, f, e;
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		cin >> s >> f >> e;
		v.push_back(Study(s, f, e));		
	}
	int answer = 0;
	sort(v.begin(), v.end());

	
	dp[0] = v[0].effect;

	for (int i = 1; i < M; i++) {
		int k = 0;
		int idx = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[j].finish + R <= v[i].start) {
				idx = j;
				break;
			}
		}
		if (idx != -1)
			dp[i] = max(dp[idx] + v[i].effect, dp[i - 1]);
		else
			dp[i] = max(v[i].effect, dp[i - 1]);

		answer = max(answer, dp[i]);
	}
	
	for (int i = 0; i < M; i++) {
		cout << dp[i] << " ";
	}
	
	cout << answer << endl;
	return 0;
}
