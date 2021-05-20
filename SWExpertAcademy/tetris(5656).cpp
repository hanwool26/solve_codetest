#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, W, H;
int answer = 0; 

int map[15][12];
int temp[15][12];
bool visit[12];

int dir_x[] = { -1,1,0,0 };
int dir_y[] = { 0,0,-1,1 };

void print_map(int (*temp)[12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "==============================" << endl;
}

int count_map(int(*temp)[12]) {
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] > 0) cnt++;
		}
	}
	return cnt;
}

void DFS(int index, int cnt, int (*map)[12]) {
	if (visit[index] == true) return;
	if (cnt == N) {
		int count = count_map(map);
		if (answer < count) {
			answer = count;
		}
		return; 
	}	
	visit[index] = true;
	memcpy(temp, map, sizeof(int)*12*15);

	print_map(temp);
	queue<pair<int,int>> q;
	int x, y,  step;
	for (int i = 6; i < 7; i++) {	// W
		// todo : implement queueing. 
		
		for (int j = 0; j < H; j++) {	// H
			if (map[j][i] == 0) continue;
			else {
				x = j;
				y = i;
				break;
			}
		}
		q.push(make_pair(x, y));
		while (!q.empty()) {
			int next_x = -1;
			int next_y = -1;
			x = q.front().first;
			y = q.front().second;
			q.pop();
			printf("(%d, %d)\n", x, y);
			
			step = map[x][y];
			map[x][y] = 0;
			for (int i = 0; i < 4; i++) {
				for (int j = 1; j < step; j++) {
					next_x = x + dir_x[i] * j;
					next_y = y + dir_y[i] * j;
				}
				if (next_x<0 || next_x>H - 1 || next_y<0 || next_y>W - 1) continue;
				q.push(make_pair(next_x, next_y));
			}
		}
		DFS(i, cnt + 1, map);
	}

	memcpy(map, temp, sizeof(int) * 12 * 15);
	visit[index] = false;
}

int main() {
	int T;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("tetris.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N >> W >> H;
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		DFS(0, 0, map);
		cout << "#" << tc + 1 << " " << answer << endl;
	}
}
