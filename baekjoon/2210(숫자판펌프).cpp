#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int board[6][6];
int digit[10][10][10][10][10][10];
int answer;

int dir_x[4] = { -1, 1, 0, 0 };
int dir_y[4] = { 0, 0, -1, 1 };

vector<int> v;

void DFS(int x, int y, int level){
	if (level == 6){
		
		if (digit[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]] == 0){
			digit[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]] = 1;
			answer++;
		}
		return;
	}

	for (int i = 0; i < 4; i++){
		int xx = x + dir_x[i];
		int yy = y + dir_y[i];

		if (xx < 1 || xx > 5 || yy < 1 || yy > 5) continue;
		v.push_back(board[xx][yy]);
		DFS(xx, yy, level + 1);
		v.pop_back();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("2210.txt", "r", stdin);

	memset(digit, 0, sizeof(digit));
	answer = 0;
	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= 5; j++){
			cin >> board[i][j];
		}
	}
	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= 5; j++){
			DFS(i, j, 0);
		}
	}
	cout << answer << endl;	
}

