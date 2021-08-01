#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N;
int map[15][15];

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

pair<int, int> s;
pair<int, int> d;

typedef struct node{
	int x;
	int y;
	int time;
	node(int a, int b, int c){
		x = a;
		y = b;
		time = c;
	}
}Node;
int answer = 0;
int BFS(){
	queue<Node> q;	
	bool visit[12][12];
	memset(visit, false, sizeof(visit));

	q.push(Node(s.first, s.second, 0));
	visit[s.first][s.second] = true;
	while (!q.empty()){
		int xx = q.front().x;
		int yy = q.front().y;
		int time = q.front().time;
		q.pop();

		if (xx == d.first && yy == d.second){
			return time;
		}

		for (int i = 0; i < 4; i++){
			int nx = xx + dir_x[i];
			int ny = yy + dir_y[i];
			if (nx < 0 || nx > N - 1 || ny < 0 || ny > N - 1 || visit[nx][ny] || map[nx][ny] == 1 ) continue;
			if ((map[nx][ny] ==2) && (time%3 != 2)) {
				q.push(Node(xx, yy, time + 1));
				//continue;
			}
			else{
				q.push(Node(nx, ny, time + 1));
				visit[nx][ny] = true;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("swimming.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
		cin >> s.first >> s.second;
		cin >> d.first >> d.second;
		
		answer = BFS();
		cout << "#" << tc << " " << answer << endl;
	}
}
