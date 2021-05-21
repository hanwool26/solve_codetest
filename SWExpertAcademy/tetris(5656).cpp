#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, W, H;
int answer = 0;

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

void print_map(int(*temp)[20]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "==============================" << endl;
}

int count_map(int(*temp)[20]) {
	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (temp[i][j] > 0) cnt++;
		}
	}
	return cnt;
}

void map_refix(int(*temp)[20]){
	int temp_contain;
	for (int i = 0; i < W; i++){
		for (int j = 0; j < H; j++){
			if (temp[j][i] == 0){
				for (int k = j; k > 0; k--){
					temp_contain = temp[k][i];
					temp[k][i] = temp[k - 1][i];
					temp[k - 1][i] = temp_contain;
				}
			}
		}
	}
}

void DFS(int index, int cnt, int(*map)[20]) {

	if (cnt == N) {
		int count = count_map(map);	
		if (answer > count) {
			answer = count;
		}
		return;
	}
	int temp[20][20];
	memcpy(temp, map, sizeof(temp));

	queue<pair<int, int>> q;
	int x, y, next_x, next_y, step;
	for (int i = 0; i < W; i++) {	// W
		// todo : implement queueing. 
		x = H-1;
		y = i;		
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
			x = q.front().first;
			y = q.front().second;	

			q.pop();
			step = map[x][y];

			if (step != 0){
				map[x][y] = 0;
				for (int i = 0; i < 4; i++) {
					next_x = -1;
					next_y = -1;
					for (int j = 1; j < step; j++) {
						next_x = x + dir_x[i] * j;
						next_y = y + dir_y[i] * j;
						if (next_x >= 0 && next_x < H && next_y >= 0 && next_y < H && \
							map[next_x][next_y] != 0){
							q.push(make_pair(next_x, next_y)); 
						}
					}
				}
			}
		}
		map_refix(map);	
		DFS(i, cnt + 1, map);	
		memcpy(map, temp, sizeof(temp));
	}	
}

int main() {
	int T;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("tetris.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		cin >> N >> W >> H;
		answer = W*H;
		int map[20][20];
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		DFS(0, 0, map);
		cout << "#" << tc + 1 << " " << answer << endl;
	}
}
