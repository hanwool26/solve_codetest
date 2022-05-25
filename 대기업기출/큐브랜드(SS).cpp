/*
- input.txt
1
5
49 48 47 48 49
36 11 11 11 43
32 11 49 11 30
40 11 11 11 29
40 42 50 29 28
1. 인접큐브간 높이 차가 제일 큰 수
-> 39 (50 - 11)
2. 인접큐브가 높이가 같을 때, 가장 큰 면적 ( 면적이 같을 경우, 더 큰 높이 숫자로 출력 )
-> ans : 11 8
3. 빗물이 고여 웅덩이가 되었을 때, 가장 큰 면적 ( 면적이 같을 경우, 더 큰 높이 숫자로 출력 )
-> ans : 29 10
제약사항
N <= 64, H <= 255
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include <time.h>
#include <set>
using namespace std;

int N;
int map[65][65];
int c_map[65][65];
bool visit[65][65];
set<pair<int, int>> parent[65][65];

#define x first
#define y second
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

void print_map(int (*map)[65]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int get_max_space(int (*map)[65], int base, int x, int y) {
	queue<pair<int, int>> q;
	int nx, ny;
	int count = 0;
	q.push({ x, y });
	visit[x][y] = true;

	while (!q.empty()) {
		x = q.front().x;
		y = q.front().y;
		q.pop();
		count++;
		for (int i = 0; i < 4; i++) {
			nx = x + dir_x[i];
			ny = y + dir_y[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1 || visit[nx][ny]) continue;
			if (map[nx][ny] != base) continue;
			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}
	return count;
}

void get_max_space_main(int (*map)[65]) {
	int max_cnt = 0;
	int max_base = 0;
	int cnt;
	int base;
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != true) {
				base = map[i][j];
				cnt = get_max_space(map, base, i, j);
				if (max_cnt < cnt) {
					max_cnt = cnt;
					max_base = base;
				}
				else if (max_cnt == cnt) {
					max_base = max(max_base, base);
				}
			}
		}
	}
	cout << max_base << " " << max_cnt << " " << endl;
}

void bfs(int (*map)[65], int base, int cx, int cy) {
	queue<pair<int, int>> q;
	stack<pair<int, int>> s;

	int nx, ny;
	int min_h = 256;
	pair<int, int> parent_pos;

	if (parent[cx][cy].size() > 0) {
		for (auto& i : parent[cx][cy]) {
			q.push({ i.x, i.y });
			s.push({ i.x, i.y });
		}
	}
	q.push({ cx,cy });
	visit[cx][cy] = true;

	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		q.pop();
		s.push({ cx,cy }); // min_h 로 flood fill

		for (int i = 0; i < 4; i++) {
			nx = cx + dir_x[i];
			ny = cy + dir_y[i];
			
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1 || visit[nx][ny]) continue;
			if (map[nx][ny] > base) {
				//min_h = min(min_h, map[nx][ny]); // 물이 차오를 수 있는 높이값 저장하고 경로 탐색 안함. 
				if (min_h > map[nx][ny]) {
					min_h = map[nx][ny];
					parent_pos = { nx,ny };
				}
				continue;
			}
			if ((nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) &&
				map[nx][ny] <= base) return; // 가장자리에 있는 곳으로 물이 새어나가므로 빗물이 고일수없는 위치라 판단. 
			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}

	if (s.size() == 1) return; // 갈곳이 없었다면 return
	
	while (!s.empty()) {
		cx = s.top().x;
		cy = s.top().y;
		map[cx][cy] = min_h;
		parent[parent_pos.x][parent_pos.y].insert({ cx, cy });
		s.pop();
	}
	return;
}

void bfs_main() {
	memcpy(c_map, map, sizeof(map));
	memset(visit, false, sizeof(visit));
	for (int i = 1; i < N-1; i++) {
		for (int j = 1; j < N-1; j++) {
			int base = map[i][j];
			bfs(c_map, base, i, j);
		}
	}
	//print_map(c_map);
	get_max_space_main(c_map);
}

int main() {                                                                                                                                                 
	clock_t start, end;
	start = clock();
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("큐브랜드.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		//make_rand();
		//get_max_space_main();
		bfs_main();

	}
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
