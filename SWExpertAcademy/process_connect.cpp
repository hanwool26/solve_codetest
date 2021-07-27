#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

enum dir{
	NONE = -1,
	LEFT = 0,
	RIGHT,
	UP,
	DOWN
};

int N;
int cell[12][12];
bool visit[12][12];
vector<pair<int, int>> core;
int core_size;
int answer;
int max_core;

int dp[12][12][5];

bool check_line(int x, int y, int dir){	
	switch (dir){
	case LEFT:
		for (int i = y - 1; i >= 0; i--){
			if (visit[x][i] == true) return false;
		}
		break;
	case RIGHT:
		for (int i = y + 1; i <N; i++){
			if (visit[x][i] == true) return false;
		}
		break;
	case UP:
		for (int i = x - 1; i >=0; i--){
			if (visit[i][y] == true) return false;
		}
		break;
	case DOWN:
		for (int i = x + 1; i <N; i++){
			if (visit[i][y] == true) return false;
		}
		break;
	}
	return true;
}

int check_visit(int x, int y, int dir){
	int count = 0;
	switch (dir){
	case LEFT:
		for (int i = y - 1; i >= 0; i--){
			visit[x][i] = true;		
			count++;
		}
		break;
	case RIGHT:
		for (int i = y + 1; i <N; i++){
			visit[x][i] = true;
			count++;
		}		
		break;
	case UP:
		for (int i = x - 1; i >= 0; i--){
			visit[i][y] = true;
			count++;
		}		
		break;
	case DOWN:
		for (int i = x + 1; i <N; i++){
			visit[i][y] = true;
			count++;
		}		
		break;
	}
	return count;
}

void DFS(int idx, int cnt, int core_num, int dir){
	//if (dp[idx][core_num][dir] < cnt) return;
	if (idx == core_size){
		if (core_num > max_core){
			max_core = core_num;
			answer = cnt;
		}
		else if (max_core == core_num){
			answer = min(answer, cnt);
		}
		return;
	}
	int x = core[idx].first;
	int y = core[idx].second;
	bool temp_visit[12][12];
	memcpy(temp_visit, visit, sizeof(visit));
	dp[idx][core_num][dir] = cnt;
	if (x == 0 || x == N - 1 || y == 0 || y == N - 1) {
		DFS(idx + 1, cnt, core_num + 1, NONE);
	}
	// LEFT
	if (check_line(x, y, LEFT)){
		int line_cnt = check_visit(x, y, LEFT);
		DFS(idx + 1, line_cnt + cnt, core_num+1, LEFT);
		memcpy(visit, temp_visit, sizeof(temp_visit));
	}
	if (check_line(x, y, RIGHT)){
		int line_cnt = check_visit(x, y, RIGHT);
		DFS(idx + 1, line_cnt + cnt, core_num + 1, RIGHT);
		memcpy(visit, temp_visit, sizeof(temp_visit));
	}
	if (check_line(x, y, UP)){
		int line_cnt = check_visit(x, y, UP);
		DFS(idx + 1, line_cnt + cnt, core_num + 1, UP);
		memcpy(visit, temp_visit, sizeof(temp_visit));
	}
	if (check_line(x, y, DOWN)){
		int line_cnt = check_visit(x, y, DOWN);
		DFS(idx + 1, line_cnt + cnt, core_num + 1, DOWN);
		memcpy(visit, temp_visit, sizeof(temp_visit));
	}
	DFS(idx + 1, cnt, core_num, NONE);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("connect_process.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		core.clear();
		memset(visit, false, sizeof(visit));
		answer = (int)1e9;
		max_core = 0;
		cin >> N;

		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 12; j++){
				for (int k = 0; k < 5; k++){
					dp[i][j][k] = (int)1e9;
				}
			}
		}
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> cell[i][j];
				if (cell[i][j] == 1) {
					core.push_back(make_pair(i, j));
					visit[i][j] = true;
				}				
			}
		}
		core_size = core.size();
		DFS(0, 0,0, NONE);
		cout << "#" << tc << " " <<  answer << endl;
	}
}
