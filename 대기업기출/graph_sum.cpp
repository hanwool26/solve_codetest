/** TC Example
1
7
1 6 3
6 5 3
5 3 2
5 2 5
2 4 4
2 7 2
**/

#include <iostream>
using namespace std;

int N;
long int graph[1001][1001];

void init_case() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			graph[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	freopen("graph_sum.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int i, j, w;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> i >> j >> w;
			graph[i][j] = graph[j][i] = w;
		}
	}
}
