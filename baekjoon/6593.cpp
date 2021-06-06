#include <iostream>
#include <queue>
using namespace std;

int L, C, R;
char building[30][30][30];
bool level_v[30][30][30];
int answer = int(1e9);

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

#define x first
#define y second

typedef struct node{
	int level;
	int x;
	int y;
}Node;

Node s;
Node e;

void print_map(){
	for (int i = 0; i < 1; i++){
		for (int j = 0; j < R; j++){
			for (int k = 0; k < C; k++){
				cout << building[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
}

void dfs(int level, int x, int y, int cnt){

	queue<pair<int, int>> q;
	bool visit[30][30] = { false, };
	int depth[30][30];
	int xx, yy, nx, ny;
	q.push({ x, y });
	depth[x][y] = 0;
	while (!q.empty()){
		xx = q.front().x;
		yy = q.front().y;
		visit[xx][yy] = true;
		q.pop();
		if (e.level == level && e.x == xx && e.y == yy){
			if (answer > cnt) answer = cnt;
			return;
		}
		if (building[level + 1][xx][yy] == '.' || building[level + 1][xx][yy] == 'E'){
			if (level_v[level + 1][xx][yy] != true){
				level_v[level + 1][xx][yy] = true;
				dfs(level + 1, xx, yy, depth[xx][yy] + cnt + 1);
				level_v[level + 1][xx][yy] = false;
			}
		}
		else if (building[level - 1][xx][yy] == '.' || building[level - 1][xx][yy] == 'E'){
			if (level_v[level - 1][xx][yy] != true){
				level_v[level - 1][xx][yy] = true;
				dfs(level - 1, xx, yy, depth[xx][yy] + cnt + 1);
				level_v[level - 1][xx][yy] = false;
			}
		}
		for (int i = 0; i < 4; i++){
			nx = xx + dir_x[i];
			ny = yy + dir_y[i];
			if (nx < 0 || nx > R - 1 || ny <0 || ny > C - 1 || visit[nx][ny] || \
				building[level][nx][ny] == '#') continue;
			depth[nx][ny] = depth[xx][yy] + 1;

			q.push({ nx, ny });
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("6593.txt", "r", stdin);
	while (true){
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		answer = int(1e9);

		for (int i = 0; i < L; i++){
			for (int j = 0; j < R; j++){
				for (int k = 0; k < C; k++){
					cin >> building[i][j][k];
					if (building[i][j][k] == 'S'){
						s.level = i;
						s.x = j;
						s.y = k;
					}
					else if (building[i][j][k] == 'E'){
						e.level = i;
						e.x = j;
						e.y = k;
					}
				}
			}
		}

		dfs(s.level, s.x, s.y, 0);
		if (answer != int(1e9)){
			printf("Escaped in %d minute(s).\n", answer);
		}
		else{
			printf("Trapped!\n");
		}
	}
}
