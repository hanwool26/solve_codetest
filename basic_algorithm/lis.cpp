#include <iostream>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v{ 6,2,5,1,7,4,8,3 };
	int dp[8];

	/* 
	* LIS Algorithm 
	*/
	for (int k = 0; k < v.size(); k++) {
		dp[k] = 1;
		for (int i = 0; i < k; i++) {
			if (v[i] < v[k]) {
				dp[k] = max(dp[k], dp[i] + 1);
			}
		}
	}
	return 0;
}

/*-------------------------------
    BOJ 2625
-------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100
typedef struct line {
	int left;
	int right;
	
	line(int left, int right) {
		this->left = left;
		this->right = right;
	}

	bool operator<(const line& l)const {
		return this->left < l.left;
	}
}Line;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("lis.txt", "r", stdin);
	int a, b, N;
	int ans = 0;
	cin >> N;
	vector<Line> v;
	vector<int> dp(N, 1);
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back(Line(a, b));
	}

	sort(v.begin(), v.end());

	for (int k = 0; k < v.size(); k++) {
		for (int i = 0; i < k; i++) {			
			if (v[i].right < v[k].right) {
				dp[k] = max(dp[k], dp[i] + 1);
			}			
		}
		ans = max(ans, dp[k]);
	}
	cout << N-ans << endl;
	return 0;
}
