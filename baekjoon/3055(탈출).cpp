#include <iostream>
#include <queue> 
#include <vector>
#include <cstring>
using namespace std;
int R, C;

char map[51][51];
bool visit[51][51];
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

int answer;

typedef struct pos{
	int x;
	int y;
	int depth;
	pos(int a, int b, int c){
		x = a;
		y = b;
		depth = c;
	}
	void init(int a, int b, int c){
		x = a;
		y = b;
		depth = c;
	}
}Pos;

Pos s(0, 0, 0), d(0, 0, 0);
vector<Pos> w;


void print_map(){
	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void bfs(){
	queue<Pos> wq;
	queue<Pos> sq;
	int base_depth = 0;
	int w_depth = 0, s_depth = 0;
	int wx, wy, wdepth, nwx, nwy, sx, sy, sdepth, nsx, nsy;

	for (auto &i : w){
		wq.push(Pos(i.x, i.y, i.depth));
	}
	sq.push(s);
	visit[s.x][s.y] = true;
	while (!sq.empty()){
		while (!wq.empty() && wq.front().depth <= base_depth){
			wx = wq.front().x;
			wy = wq.front().y;
			int wdepth = wq.front().depth;
			wq.pop();
			for (int i = 0; i < 4; i++){
				nwx = wx + dir_x[i];
				nwy = wy + dir_y[i];
				if (nwx < 1 || nwx > R || nwy < 1 || nwy > C || map[nwx][nwy] == 'X' || map[nwx][nwy] == '*' || \
					map[nwx][nwy] == 'S' || map[nwx][nwy] == 'D')continue;
				wq.push(Pos(nwx, nwy, wdepth + 1));
				map[nwx][nwy] = '*';
			}			
		}	

		while (!sq.empty() && sq.front().depth <= base_depth){
			sx = sq.front().x;
			sy = sq.front().y;
			sdepth = sq.front().depth;
			sq.pop();
			if (map[sx][sy] == 'D'){
				answer = sdepth;
				break;
			}
			for (int i = 0; i < 4; i++){
				nsx = sx + dir_x[i];
				nsy = sy + dir_y[i];
				if (nsx < 1 || nsx > R || nsy < 1 || nsy > C || map[nsx][nsy] == 'X' || map[nsx][nsy] == '*' || visit[nsx][nsy] == true) continue;

				sq.push(Pos(nsx, nsy, sdepth + 1));
				visit[nsx][nsy] = true;
			}
		}		

		base_depth++;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("3055.txt", "r", stdin);
	cin >> R >> C;

	for (int i = 1; i <= R; i++){
		for (int j = 1; j <= C; j++){
			cin >> map[i][j];
			if (map[i][j] == 'S') s.init(i, j, 0);
			else if (map[i][j] == 'D') d.init(i, j, 0);
			else if (map[i][j] == '*') w.push_back(Pos(i, j, 0));

		}
	}
	answer = -1;
	bfs();
	if (answer == -1) cout << "KAKTUS" << endl;
	else cout << answer << endl;

	return 0;
}
