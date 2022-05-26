#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define x first
#define y second

int W, H;
int map[1000][1000];
pair<int, int> start;

int dir_x[] = { -1,1,0,0 };
int dir_y[] = { 0,0,-1,1 };

typedef struct node {
	int x;
	int y;
	int dis;
	node(int x, int y, int dis) {
		this->x = x;
		this->y = y;
		this->dis = dis;
	}
}Node;

void print_map() {
	for (int i = 190; i < 210; i++) {
		for (int j = 55; j < 75; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int answer = 1e9;

int visit[1000][1000];
vector<Node> stre_pos;
void bfs(int cx, int cy, int flag, int dis) {	// flag == 1일 경우 산딸기를 만남. 
	queue<Node> q;	
	memset(visit, false, sizeof(visit));
	q.push(Node(cx,cy,dis));
	visit[cx][cy];

	while (!q.empty()) {
		cx = q.front().x;
		cy = q.front().y;
		dis = q.front().dis;
		q.pop();
		if (dis > answer) return;
		if (map[cx][cy] == 4 && flag == 0) {
		//	cout << cx << " " << cy << endl;
			stre_pos.push_back(Node(cx, cy, dis));
		}
		if (map[cx][cy] == 3 && flag == 1) {	// 기사를 만남. 		
			answer = min(answer, dis);	
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cx + dir_x[i];
			int ny = cy + dir_y[i];
			if (nx < 0 || nx > H - 1 || ny < 0 || ny > W - 1 || visit[nx][ny]) continue; // 지도에서 벗어날 경우
			if (map[nx][ny] == 1 || (flag == 0 && map[nx][ny] == 3)) continue;	// 벽이 있거나 산딸기 없이 기사를 만날 경우
			q.push(Node(nx, ny, dis+1));
			visit[nx][ny] = true;
		}
	}
}


/*
void dfs(int x, int y, bool flag, int sum) {
	if (x < 0 || x > H - 1 || y < 0 || y > W - 1 || visit[x][y] || map[x][y] == 1) return;
	if (map[x][y] == 3){
		if (flag == true) {
			answer = min(answer, sum);
		}
		return;
	}

	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];
		if (map[nx][ny] == 4 && flag == 0) {
			dfs(nx, ny, 1, sum + 1);
		}
		else if (map[nx][ny] == 4 && flag == 1) continue;
		dfs(nx, ny, 0, sum + 1);
	}
	visit[x][y] = false;
}
*/
int main() {
	freopen("숲속의기사.txt", "r", stdin);
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				start.x = i;
				start.y = j;
			}
		}
	}
	//print_map();
	bfs(start.x, start.y, 0, 0);
	for (auto& n : stre_pos) {
		bfs(n.x, n.y, 1, n.dis);
	}
	cout << answer << endl;

	return 0;
}
