#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
int N, M;
vector<pair<int, int>> v;
int map[9][9];
int temp[9][9];
int answer = 0;
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

void print_map(int(*map_c)[9]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << map_c[i][j] << " ";
		}
		cout << endl;
	}
	cout << "=======================" << endl;
}

void copy_map(int(*dest)[9], int(*source)[9]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dest[i][j] = source[i][j];
		}
	}
}

int BFS(int(*temp_map)[9], int(*map)[9]) {
	int cnt = 0;
	copy_map(temp_map, map);
	queue<pair<int, int>> q;

	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i].first, v[i].second });
	}

	int xx, yy, nx, ny;

	while (!q.empty()) {
		xx = q.front().first;
		yy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nx = xx + dir_x[i];
			ny = yy + dir_y[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M || \
				temp_map[nx][ny] > 0) continue;

			if (temp_map[nx][ny] != 2) {
				temp_map[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (temp[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void DFS(int x, int cnt) {
	if (cnt > 3) return;
	if (cnt == 3) {
		int count = 0;
		count = BFS(temp, map);
		if (answer < count) {
			answer = count;
		}
		return;
	}
	for (int i = x; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] >= 1) continue;
			map[i][j] = 1;
			DFS(i, cnt + 1);
			map[i][j] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("14502.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				v.push_back({ i, j });
			}
		}
	}
	DFS(1, 0);
	cout << answer << endl;
}
