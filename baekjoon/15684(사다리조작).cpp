#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;
int N, M;
vector<pair<int, int>> v;
int map[9][9];
bool visit[9][9];
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

int temp[9][9];
int answer = 0;

void BFS(int x, int y, int(*temp_map)[9]) {
	queue<pair<int, int>> q;
	q.push({ x, y });
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
}

int count_map(int(*temp)[9]) {
	int cnt = 0;
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
		copy_map(temp, map);
		int count = 0;
		for (int i = 0; i < v.size(); i++) {
			BFS(v[i].first, v[i].second, temp);
		}
		count = count_map(temp);
		if (answer < count) {
			answer = count;
		}
		return;
	}
	for (int i = x; i <= N; i++) {
		for (int j = 1; j < M; j++) {
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

	clock_t start, end;

	start = clock();
	freopen("14502.txt", "r", stdin);
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
	end = clock();
	cout << "duration : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
