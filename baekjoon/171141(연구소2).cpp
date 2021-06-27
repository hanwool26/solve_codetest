#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int s_num;
int map[51][51];

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };
int visit[10];
int answer;
vector<int> v;

typedef struct virus{
	int x;
	int y;
	int depth;
	virus(int a, int b, int c){
		x = a;
		y = b;
		depth = c;
	}
}Virus;

vector<Virus> s;
vector<Virus> r_v;

void print_map(int (*map)[51]){
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			printf("%c ", ((map[i][j] == -1) ? '-' : map[i][j]+48));
		}
		cout << endl;
	}
	cout << endl;
}

int find_value(int(*map)[51]){
	int max = 0;
	int virus_cnt = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (map[i][j] == 0) virus_cnt++;
			if (max < map[i][j]) max = map[i][j];
		}
	}
	if (virus_cnt == M) return max;
	else return int(1e9);
}

void bfs(int (*map)[51]){
	queue<Virus> q;
	int visit[51][51];
	memset(visit, false, sizeof(visit));
	
	for (auto &i : r_v){
		q.push(i);
		visit[i.x][i.y] = true;
	}

	while (!q.empty()){
		Virus temp = q.front();
		q.pop();
		int xx = temp.x;
		int yy = temp.y;
		int depth = temp.depth;
		map[xx][yy] = depth;
		for (int i = 0; i < 4; i++){
			int nx = xx + dir_x[i];
			int ny = yy + dir_y[i];
			if (nx < 1 || nx > N || ny < 1 || ny > N || map[nx][ny] == -1 || visit[nx][ny]) continue;
			q.push({ nx, ny, depth + 1 });
			visit[nx][ny] = true;
		}				
	}

	int temp_value = find_value(map);
	if (answer > temp_value) answer = temp_value;
}

void DFS(int idx, int count){
	if (count == M){
		int temp_map[51][51];
		r_v.clear();
		memcpy(temp_map, map, sizeof(map));
		for (auto &i : v){			
			r_v.push_back(Virus(s[i].x, s[i].y, s[i].depth));
		}
		bfs(temp_map);
		//print_map(temp_map);
		return;
	}
	for (int i = idx; i < s_num; i++){
		v.push_back(i);
		DFS(i+1, count + 1);
		v.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("171141.txt", "r", stdin);

	cin >> N >> M;
	answer = int(1e9);
	s_num = 0;
	s.clear();
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> map[i][j];
			if (map[i][j] == 2){
				s.push_back(virus(i, j, 0));
				s_num++;
			}
			else if (map[i][j] == 1){
				map[i][j] = -1;
			}
		}
	}
	DFS(0, 0);
	if (answer == int(1e9)) answer = -1;
	cout << answer << endl;
	
	return 0;
}
