#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define x first
#define y second

int R, C;
int map[101][101];
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

void print_map(){
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "===========================" << endl;
}

void BFS(int x, int y, int k){
	queue<pair<int, int>> q;
	int xx, yy, nx, ny;
	q.push({ x, y });
	map[x][y] = 2;

	while (!q.empty()){
		xx = q.front().x;
		yy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++){
			nx = xx + dir_x[i];
			ny = yy + dir_y[i];
			if (nx < 1 || nx > R || ny < 1 || ny > C || \
				map[nx][ny] > 1) continue;
			if (map[nx][ny] == k){
				map[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}		
	}
}

void check_hole(){
	bool visit[101][101];
	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	int xx, yy, nx, ny;
	q.push({ 1, 1 });
	visit[1][1] = true;

	while (!q.empty()){
		xx = q.front().x;
		yy = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++){
			nx = xx + dir_x[i];
			ny = yy + dir_y[i];
			if (nx < 1 || nx > R || ny < 1 || ny > C || visit[nx][ny] || map[nx][ny] == 1) continue;
			if (map[nx][ny] == 0){
				map[nx][ny] = 2;
			}
			q.push({ nx, ny });
			visit[nx][ny] = true;
		}
	}
	
}

int get_count(){
	int cnt = 0;
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			if (map[i][j] == 1){
				cnt++;
			}
		}
	}
	return cnt;
}

void DFS(int time, int remain){
	vector<pair<int, int>> v;
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			for (int k = 0; k < 4; k++){
				if (map[i][j] == 1 && map[i + dir_x[k]][j + dir_y[k]] == 2){
					v.push_back({ i, j });
					break;
				}
			}
		}
	}
    int v_size = v.size();
	for (int i = 0; i < v_size; i++){
		int xx = v[i].x;
		int yy = v[i].y;
		map[xx][yy] = 2;
	}
	check_hole();
	if (get_count() == 0){
		cout << time << endl << remain << endl;
		return;
	}
	DFS(time + 1, get_count());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("2636.txt", "r", stdin);
	cin >> R >> C;

	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cin >> map[i][j];
		}
	}
	BFS(1,1,0);
	if (get_count() == 0){
		cout << 0 << " " << 0 << endl;
	}
	else{
		DFS(1, get_count());
	}
	return 0;
}
