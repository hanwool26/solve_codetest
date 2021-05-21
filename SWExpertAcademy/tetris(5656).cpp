#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int N, W, H;
int answer = 0;

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

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

void crush(int x, int y, int(*map)[20]){
	int step = map[x][y];
	map[x][y] = 0;
	if (step == 1) return;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < step; j++) {
			int next_x = x + dir_x[i] * j;
			int next_y = y + dir_y[i] * j;
			if (next_x < 0 || next_x > H - 1 || next_y < 0 || next_y > W - 1 || !map[next_x][next_y]) continue;
			if (map[next_x][next_y] == 1){
				map[next_x][next_y] = 0;
				continue;
			}
			q.push({ next_x, next_y });
		}
	}
}

int topPos(int y, int(*map)[20]){
	for (int i = 0; i < H; i++) {	// H
		if (map[i][y] > 0) return i;
	}
	return -1;
}

void DFS(int cnt, int(*map)[20]) {
	if (cnt == N) {	
		//answer = min(answer, count_map(map));
		return;
	}
	else{
		int temp[20][20] = { 0, };
		int x, y;
        memcpy(temp, map, sizeof(int)* 20 * 20);        
		for (int i = 0; i < W; i++) {	// W
			// todo : implement queueing. 					
			x = topPos(i, map);
			y = i;
			if (x == -1 || map[x][y] == 0) continue;
			crush(x, y, map);
			while (!q.empty()) {
				x = q.front().first;
				y = q.front().second;

				q.pop();
				crush(x, y, map);
			}
			map_refix(map);
			DFS(cnt + 1, map);
			answer = min(answer, count_map(map));
			memcpy(map, temp, sizeof(int)* 20 * 20);
		}		
	}	
}

int main() {
	int T;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("tetris.txt", "r", stdin);
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
		DFS(0, map);
		cout << "#" << tc + 1 << " " << answer << endl;
	}
}
