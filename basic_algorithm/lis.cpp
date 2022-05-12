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
	/* BOJ 2565
	for (int i = 0; i < 8; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;


	freopen("lis.txt", "r", stdin);
	int a, b, N;
	cin >> N;
	int max_n = 0;
	
	memset(arr, 0, sizeof(0));
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[a] = b;
		max_n = max(max_n, max(a, b));
	}*/
	return 0;
}
