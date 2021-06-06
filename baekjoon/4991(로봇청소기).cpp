#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int C, R;
char map[20][20];
int visit[10][20][20];

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

int dirty_cnt;
int answer;

typedef struct node{
	int x;
	int y;
	int depth;
	node(int a, int b, int  c){
		x = a;
		y = b;
		depth = c;
	}
}Node;
Node s(0, 0, 0);


void DFS(int x, int y, int cnt, int dis_cnt){
	if (cnt == dirty_cnt){
		if (answer > dis_cnt){
			answer = dis_cnt;
		}
		return;
	}
	visit[cnt][x][y] = true;
	queue<Node> q;
	q.push((Node(x, y, 0)));
	int xx, yy, nx, ny;
	int cur_depth;
	while (!q.empty()){
		Node cur = q.front();
		xx = cur.x;
		yy = cur.y;
		cur_depth = cur.depth;
		q.pop();
		if (map[xx][yy] == '*' && !visit[cnt][xx][yy]){
			map[xx][yy] = '.';
			DFS(xx, yy, cnt + 1, dis_cnt + cur_depth);
			break;
		}
		visit[cnt][xx][yy] = true;
		for (int i = 0; i < 4; i++){
			nx = xx + dir_x[i];
			ny = yy + dir_y[i];
			if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1 || visit[cnt][nx][ny] || \
				map[nx][ny] == 'x') continue;
			q.push(Node(nx, ny, cur_depth + 1));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char temp[20];
	freopen("4991.txt", "r", stdin);
	while (true){
		cin >> C >> R;
		if (C == 0 && R == 0) break;
		answer = int(1e9);
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 20; j++){
				for (int k = 0; k < 20; k++){
					visit[i][j][k] = false;
				}
			}
		}
		dirty_cnt = 0;
		if (C == 0 && R == 0) break;
		for (int i = 0; i < R; i++){
			cin >> temp;
			for (int j = 0; j < C; j++){
				map[i][j] = temp[j];
				if (map[i][j] == 'o'){
					s.x = i;
					s.y = j;
					s.depth = 0;
				}
				else if (map[i][j] == '*') dirty_cnt++;
			}
		}
		DFS(s.x, s.y, 0, s.depth);
		if (answer != int(1e9)) cout << answer << endl;
		else cout << -1 << endl;

	}
	return 0;
}
