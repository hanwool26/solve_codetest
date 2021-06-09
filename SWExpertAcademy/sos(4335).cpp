#include <iostream>
using namespace std;

int num_blocks;
int blocks[20][3];
int dp[20][(1 << 20) - 1][3];

int cal(int b, int use, int direc, int w, int d)
{
	int& height = dp[b][use][direc];
	
	if (height != -1) {
		return height;
	}
	int result = 0;
	for (int i = 0; i < num_blocks; i++) {
		if ((use & (1 << i)) != 0) {
			continue;
		}
		if ((w >= blocks[i][1] && d >= blocks[i][2]) || (w >= blocks[i][2] && d >= blocks[i][1])) {
			result = blocks[i][0] + cal(i, use | (1 << i), 0, blocks[i][1], blocks[i][2]);
			if (height < result) {
				height = result;
			}
		}
		if ((w >= blocks[i][0] && d >= blocks[i][2]) || (w >= blocks[i][2] && d >= blocks[i][0])) {
			result = blocks[i][1] + cal(i, use | (1 << i), 1, blocks[i][0], blocks[i][2]);
			if (height < result) {
				height = result;
			}
		}
		if ((w >= blocks[i][1] && d >= blocks[i][0]) || (w >= blocks[i][0] && d >= blocks[i][1])) {
			result = blocks[i][2] + cal(i, use | (1 << i), 2, blocks[i][1], blocks[i][0]);
			if (height < result) {
				height = result;
			}
		}
	}
    if (result  == 0) height = 0;
    return height;
}
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> num_blocks;
		for (int i = 0; i < num_blocks; i++) {
			for (int k = 0; k < (1 << num_blocks)-1; k++) {
				dp[i][k][0] = dp[i][k][1] = dp[i][k][2] = -1;
			}
			cin >> blocks[i][0] >> blocks[i][1] >> blocks[i][2];
		}
		cout << "#" << tc + 1 << " " << cal(0, 0, 0, 10001, 10001) << endl;
	}
}
