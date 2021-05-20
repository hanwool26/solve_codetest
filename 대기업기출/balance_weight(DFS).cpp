#include <iostream>
#include <time.h>

using namespace std;

int A, B, N;
int weight[500];
int answer;
bool dp[1 << 20 - 1][2];

enum dir {
	LEFT,
	RIGHT
};

bool result[100000];

void init_case() {
	memset(result, false, sizeof(result));
	for (int i = 0; i < (1 << 20) - 1; i++) {
		dp[i][0] = dp[i][1] = false;
	}
}

void DFS(int left, int right, int use, int flag, bool used) {	
	
	if (result[abs(left-right)] == false) {
		result[abs(left-right)] = true;
	}

	if (dp[use][flag] == true) return;
	dp[use][flag] = true;
	
	//printf("%d\n", abs(left - right));

	for (int i = 0; i < N; i++) {
		if ((use & (1 << i)) != 0) continue;
		DFS(left + weight[i], right, use | (1 << i), LEFT, used);
		DFS(left, right + weight[i], use | (1 << i), RIGHT, used);

	}
}

bool is_satisfied() {
	for (int i = A; i <= B; i++) {
		if (result[i] == false) {
			//cout << i << " ";
			return false;
		}
	}
	return true;
}

int main() {
	clock_t start, end;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;

	start = clock();
	freopen("balance_weight.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> A >> B >> N;
		answer = 0;

		init_case();
		for (int i = 0; i < N; i++) {
			cin >> weight[i];
		}
				
		DFS(0, 0, 0, 0, 0);
		N++;
		if (is_satisfied() == false) {
			
			for (int i = A; i <= B; i++) {
				bool flag = false;
				for (int j = 0; j < N - 1; j++) {
					if (i == weight[j]) flag = true;
				}
				if (flag == false) {
					weight[N - 1] = i;
					init_case();
					DFS(0, 0, 0, 0, 0);
					if (is_satisfied() == true) {
						answer = i;
						break;
					}
				}
			}
		}
		cout << "#" << tc + 1 << " " << answer << endl;
	}
	end = clock();
	cout << "duration : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
