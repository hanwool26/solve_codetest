#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
bool visit[101][101];
int N;
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };
int answer;

typedef struct node{
	int x;
	int y;
	int time;
	node(int a, int b, int c){
		x = a;
		y = b;
		time = c;
	}
	bool operator<(const node &b)const{
		return time > b.time;
	}
}Node;

void BFS(){
	priority_queue<Node> q;
	Node s(1, 1, 0);
	q.push(s);
	while (!q.empty()){
		Node temp = q.top();
		int xx = temp.x;
		int yy = temp.y;
		int time = temp.time;
		q.pop();

		if (xx == N && yy == N){
			answer = time;
			break;
		}

		visit[xx][yy] = true;
		for (int i = 0; i < 4; i++){
			int nx = xx + dir_x[i];
			int ny = yy + dir_y[i];
			if (nx < 1 || nx > N || ny < 1 || ny > N || visit[nx][ny]) continue;
			q.push(Node(nx, ny, time+map[nx][ny]));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;

	freopen("1249.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		memset(visit, false, sizeof(visit));
		answer = 0;
		cin >> N;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				scanf("%1d", &map[i][j]);
			}
		}
		BFS();
		cout << "#" << tc << " " << answer << endl;
	}
}
