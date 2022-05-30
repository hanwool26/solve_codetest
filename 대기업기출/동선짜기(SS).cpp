/*
문제 : 동선짜기
- TC 30개, C++ 2초 512MB 메모리 사용 
- 관람객이 몰릴 경우를 대비해서 동선을 결정 -> 동선 좌우로 전시품을 설치, 이 경우 관람객이 움직이는 동선의 최대 길이로 출력
- 입구는 좌측 상단, 출구는 우측 하단
- 전시관 중간중간 기둥이 존재
- 갈래길이 존재하면 안됨, 서로 다른 부분이 맞닿아 있으면 안됨(2칸까지 가능)

제한조건 :
1. 3<= W, H <=7
2. 기둥 개수는 10개 이하
3. 4방향으로만 이동
4. 빈공간은 '.' 기둥은 'X' 로 입력
5. 동선의 최대길이는 입구와 출구 포함
6. 동선은 반드시 입구와 출구가 연결
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

char map[9][9];
bool visit[9][9];

int T;
int W, H;
int ans;

// DOWN UP LEFT RIGHT
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0,0,-1,1 };

void print_map() {
	for (int i = 1; i <= H; i++) {
		
		for (int j = 1; j <= W; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print_visit() {
	for (int i = 1; i <= H; i++) {

		for (int j = 1; j <= W; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

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

int bfs(int sx, int sy, int fx, int fy) {
	queue<Node> q; 
	q.push(Node(sx, sy, 0));

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dis = q.front().dis;
		q.pop();

		if (dis > 2) return 0; // false;
		if (x == fx && y == fy && dis <= 2)  return dis; // return true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (nx < 1 || nx > H || ny < 1 || ny > W || visit[nx][ny] == false)continue;
			q.push(Node(nx, ny, dis + 1));
		}		
	}
	return 0;
}

bool check_road(int x, int y) {
	if (x < 1 || x > H || y < 1 || y > W || visit[x][y] || map[x][y] == 'X') return false;
	int cross_x[] = { -1, -1, 1, 1 };
	int cross_y[] = { -1, 1, -1, 1 };
	
	for (int i = 0; i < 4; i++) {
		int nx = x + cross_x[i];
		int ny = y + cross_y[i];
		// if there is cross from current_pos; 
		if (nx <1 || nx > H || ny < 1 || ny > W) continue;
		if (visit[nx][ny])
			if(bfs(x, y, nx, ny) == 0) return false;
	}
	
	// 인접 길 체크
	
	if ((visit[x - 1][y] || visit[x + 1][y]) && (visit[x][y - 1] || visit[x][y + 1])) return false;
	
	// 갈래길 체크
	if (visit[x - 1][y - 1] && visit[x - 1][y] && visit[x - 1][y + 1]) return false;
	if (visit[x - 1][y - 1] && visit[x][y-1] && visit[x + 1][y - 1]) return false;
	if (visit[x + 1][y - 1] && visit[x + 1][y] && visit[x + 1][y + 1]) return false;
	if (visit[x - 1][y + 1] && visit[x][y + 1] && visit[x + 1][y + 1]) return false;

	// 싸이클 체크
	if ((visit[x - 1][y] && visit[x + 1][y]) || (visit[x][y - 1] && visit[x][y + 1])) return false;
	
	return true;
}

void dfs(int x, int y, int cnt) {
	if (x == H && y == W) {
		//if (cnt == 27) print_visit();
		ans = max(ans, cnt);
		return;
	}

	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir_x[i];
		int ny = y + dir_y[i];
		if (check_road(nx, ny) == false) continue;
		dfs(nx, ny, cnt + 1);
	}
	visit[x][y] = false;

}

void init_test() {
	memset(visit, false, sizeof(visit));
	ans = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("make_road.txt", "r", stdin);
	cin >> T;
	string input;
	for (int tc = 1; tc <= T; tc++) {
		init_test();
		cin >> W >> H;
		for (int i = 1; i <= H; i++) {
			cin >> input;
			for (int j = 1; j <= input.length(); j++) {
				map[i][j] = input[j - 1];
			}
		}
		print_map();
		dfs(1, 1, 1);
		cout << "#" << tc << " " << ans << endl;
	}
}
