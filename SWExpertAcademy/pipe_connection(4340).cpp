#include <iostream>
using namespace std;

int map[50][50];
int visit[50][50];
int N;
int answer = 0;

typedef struct _pair{
	int x;
	int y;
}Pair;

Pair pipe_dir[7][2] = {
	{ { 0, 0 }, { 0, 0 } },	// 0
	{ { 0,-1 }, { 0, 1 } },	// 1
	{ {-1, 0 }, { 1, 0 } },	// 2
	{ { 1, 0 }, { 0, 1 } },	// 3
	{ { 1, 0 }, { 0,-1 } },	// 4
	{ {-1, 0 }, { 0,-1 } },	// 5
	{ {-1, 0 }, { 0, 1 } },	// 6
};

void DFS(int x, int y, int pipe, int cnt){
	if (x == N - 1 && y == N - 1 && (pipe == 1 || pipe == 6)){
		if (answer > cnt){
			answer = cnt;
		}
		return;
	}
	if (visit[x][y] == 1)return;
	visit[x][y] = 1;
	for (int i = 1; i < 7; i++){
		for (int j = 0; j < 2; j++){
			int next_x = x + pipe_dir[i][j].x;
			int next_y = y + pipe_dir[i][j].y;
			if (map[next_x][next_y] == 0) continue;
			for (int k = 0; k < 2; k++){
				if (pipe_dir[i][j].x+pipe_dir)
			}
		}
	}
	visit[x][y] = 0;
}

int main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("pipe_connection_input.txt", "r", stdin);
	cin >> T;

	for (int tc = 0; tc < T; tc++){
		cin >> N;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
		answer = N*N;

		cout << "#" << tc + 1 << " " << answer << endl;
	}
}
