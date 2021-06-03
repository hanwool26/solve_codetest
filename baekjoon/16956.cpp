#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define x first
#define y second

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

int R, C;
char map[500][500];
bool visit[500][500];
vector<pair<int, int>> w;


void print_map(){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS(){
	queue<pair<int, int>> q;

	for (int i = 0; i < w.size(); i++){
		q.push({ w[i].x, w[i].y });
		visit[w[i].x][w[i].y] = true;

		while (!q.empty()){
			int cur_x = q.front().x;
			int cur_y = q.front().y;
			q.pop();

			for (int i = 0; i < 4; i++){
				int x = cur_x + dir_x[i];
				int y = cur_y + dir_y[i];
				if (visit[x][y] == true) continue;
				if (x < 0 || x > R - 1 || y < 0 || y > C - 1 || \
					map[x][y] == 'W' || map[x][y] == 'D') continue;
				if (map[x][y] == 'S') {
					map[cur_x][cur_y] = 'D';
					continue;
				}
				q.push({ x, y });
				visit[x][y] = true;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("16956.txt", "r", stdin);
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
			if (map[i][j] == 'W'){
				w.push_back({ i, j });
			}
		}
	}
	BFS();
	print_map();
}
