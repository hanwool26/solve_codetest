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
