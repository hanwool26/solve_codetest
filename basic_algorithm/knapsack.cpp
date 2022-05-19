#include <iostream>
using namespace std;

int N = 4;
int item[][2] = {
	{5,12}, {3,8}, {6,14}, {4,8}
};

#define value 1
#define weight 0

int dp[20][20];

int knapsack(int pos, int capacity) {
	if (pos == N) return 0;
	int ret = dp[pos][capacity];
	if (ret != -1)
		return ret;
	if (item[pos][weight] <= capacity) {
		ret = knapsack(pos + 1, capacity - item[pos][weight]) + item[pos][value];
	}
	ret = max(ret, knapsack(pos + 1, capacity));
	return dp[pos][capacity] = ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cout << knapsack(0, 11) << endl;
}

#include <iostream>
#include <time.h>

using namespace std;

int value[4][2] = { {6,13}, {4,8}, {3,6}, {5,12} };
int bag[100][100];
int dp[100];

void print_bag() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <=7 ; j++) {
			cout << bag[i][j] << " ";
		}
		cout << endl;
	}
}
int ans = 0;

void dfs(int idx, int value_sum, int weight_sum) {
	if (weight_sum > 7) return;
	if (idx == 4) {
		ans = max(ans, value_sum);
		return;
	}
	dfs(idx + 1, value[idx][1] + value_sum, value[idx][0] + weight_sum);
	dfs(idx + 1, value_sum, weight_sum);
}

int main() {
	clock_t s, f;
	s = clock();
	cout << endl << "-----2D ARRAY-----" << endl;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 7; j++) {
			int cur_weight = value[i-1][0];
			int cur_val = value[i-1][1];

			if (cur_weight <= j) {
				bag[i][j] = max(bag[i - 1][j], cur_val + bag[i - 1][j - cur_weight]);
			}
			else {
				bag[i][j] = bag[i - 1][j];
			}
		}
	}
	print_bag();
	cout << endl << "-----1D ARRAY-----" << endl << endl;
	for (int i = 1; i <= 4; i++) {		
		int cur_weight = value[i - 1][0];
		int cur_val = value[i - 1][1];
		for(int j=7; j>=cur_weight; j--){
				dp[j] = max(dp[j], cur_val + dp[j - cur_weight]);			
		}
	}
	for (int i = 1; i <= 7; i++) {
		cout << dp[i] << " ";
	}
	cout << endl << "------ DFS ------" << endl;
	
	dfs(0, 0, 0);
	cout << ans << endl;
	cout << endl << "--------------------" << endl;
	

	return 0;
}
