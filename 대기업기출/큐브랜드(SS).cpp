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
#include <queue>
using namespace std;

int N;
int map[65][65];
bool visit[65][65];

#define x first
#define y second
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

void print_map(){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
}

int get_max_space(int base, int x, int y){
	queue<pair<int, int>> q;
	int nx, ny;
	int count = 0;
	q.push({ x, y });
	visit[x][y] = true;

	while (!q.empty()){
		x = q.front().x;
		y = q.front().y;
		q.pop();
		count++;
		for (int i = 0; i < 4; i++){
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

void get_max_space_main(){
	int max_cnt = 0;
	int max_base = 0;
	int cnt;
	int base;
	memset(visit, false, sizeof(visit));


	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (visit[i][j] != true){
				base = map[i][j];
				cnt = get_max_space(base, i, j);
				if (max_cnt < cnt){
					max_cnt = cnt;
					max_base = base;
				}
				else if (max_cnt == cnt){
					max_base = max(max_base, base);
				}
			}
		}
	}
	cout << max_base << " " << max_cnt << " ";
}

int bfs(int base, int x, int y){
	memset(visit, false, sizeof(visit));
	//if (x == 0 || y == 0 || x == N - 1 || y == N - 1) return 0;
	int nx, ny;
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[x][y] = true;
	while (!q.empty()){
		x = q.front().x;
		y = q.front().y;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++){
			nx = x + dir_x[i];
			ny = y + dir_y[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1) continue;
			if (base < map[nx][ny] || visit[nx][ny]) continue;
			if ((nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) && map[nx][ny] != base) continue;
			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}
	return cnt;
}

void bfs_main(){
	int max_cnt = 0;
	int max_base = 0;
	int cnt;
	int base;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			base = map[i][j];
			cnt = bfs(base, i, j);
			if (max_cnt < cnt){
				max_cnt = cnt;
				max_base = base;
			}
			else if (max_cnt == cnt){
				max_base = max(max_base, base);
			}
		}
	}
	cout << max_base << " " << max_cnt << endl;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("큐브랜드.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
		get_max_space_main();
		bfs_main();
	}
	return 0;
}
