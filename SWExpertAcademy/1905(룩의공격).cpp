#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;

bool rook[301][301];
int temp;
int answer;

vector<pair<int, int>> v;

void print_map(int (*map)[301]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int cal_sum(int x, int y, int (*temp)[301]) {
	int sum = 0;
	temp[x][y] = 0;
	for (int j = 1; j <= N; j++) {
		sum += temp[x][j];
		temp[x][j] = 0;
	}
	for (int j = 1; j <= N; j++) {
		sum += temp[j][y];
		temp[j][y] = 0;
	}
	return sum;
}

void mem_cpy(int (*dst)[301], int (*src)[301]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

void DFS(int y, int cnt, int (*map)[301], int sum) {
	if (cnt == 2) {
		answer = max(answer, sum);
		return;
	}

	int temp[301][301];
	memset(temp, 0, sizeof(temp));
	mem_cpy(temp, map);
	print_map(temp);

	for (int i = 1; i <= N; i++) {
		for (int j = y; j <= N; j++) {
			if (rook[i][j] == true) continue;
			rook[i][j] = true;
			int num = cal_sum(i, j, map);
			DFS(y, cnt + 1, map, num+sum);
			mem_cpy(map, temp);
			rook[i][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("1904.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		memset(rook, false, sizeof(rook));
		int map[301][301];
		memset(map, 0, sizeof(map));
		
		answer = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> map[i][j];
			}
		}
		DFS(1, 0, map, 0);
		cout << "#" << tc << " " << answer << endl;
	}
}
