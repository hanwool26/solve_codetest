#include <iostream>
using namespace std;

int N;
int map[20][20];

int start_x, start_y;
int answer = -1;
int dp[100] = { 0, };
int dir[][2] = { { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };

void init_case(){
	answer = -1;
	for (int i = 0; i < 100; i++){
		dp[i] = 0;
	}
}

void DFS(int x, int y, int cnt, int rotate, int dir_num){
	if (x == start_x && y == start_y && cnt != 0 && rotate==3){
		if (answer < cnt){
			answer = cnt;
		}
		return;
	}
	if (dp[map[x][y]] != 0 || rotate > 3) return;
	dp[map[x][y]] = 1;

	for (int i = 0; i < 4; i++){
		int next_x = x + dir[i][0];
		int next_y = y + dir[i][1];
		
		if (next_x<0 || next_x>N - 1 || next_y<0 || next_y>N - 1) continue;		
		DFS(next_x, next_y, cnt + 1, i == dir_num ? rotate : rotate + 1, i);		
	}
	dp[map[x][y]] = 0;
}

int main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("dessert_cafe_input.txt", "r", stdin);

	cin >> T;
	for (int tc = 0; tc < T; tc++){
		init_case();
		cin >> N;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				start_x = i;
				start_y = j;
				DFS(start_x, start_y,0,0,0);
			}
		}		
		cout << "#" << tc + 1 << " " << answer << endl;
	}
}
