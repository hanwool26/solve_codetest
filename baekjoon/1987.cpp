#include <iostream>
using namespace std;

int R, C, answer;

char map[20][20];
char tmp[21];    // 문자배열의 경우 NULL 문자 고려.
int dp[26];

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

void print_map(){
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(int x, int y, int cnt){
	if (dp[map[x][y] - 'A'] == 1) return;
	if (answer < cnt){
		answer = cnt;
	}

	int next_x, next_y;	
	dp[map[x][y] - 'A'] = 1;

	for (int i = 0; i < 4; i++){
		next_x = x + dir_x[i];
		next_y = y + dir_y[i];

		if (next_x <0 || next_y < 0 || next_x > R - 1 || next_y > C - 1) continue;
		DFS(next_x, next_y, cnt + 1);

	}
	dp[map[x][y] - 'A'] = 0;
}

int main(){
	//freopen("1987.txt", "r", stdin);
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		cin >> tmp;
		for (int j = 0; j < C; j++){
			map[i][j] = tmp[j];
		}
	}
	answer = 0;
	DFS(0, 0, 1);
	cout << answer << endl;
}
