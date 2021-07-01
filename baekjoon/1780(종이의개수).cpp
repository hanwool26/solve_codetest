#include <iostream>
using namespace std;

int N;
#define MAX 2188
int board[MAX][MAX];
int num[3] = { -1, 0, 1 };
int answer[3] = { 0, 0, 0 };

void print_board(int x, int y, int N){
	for (int i = x; i < x+N; i++){
		for (int j = y; j < y+N; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool find_paper(int x, int y, int base_num, int N){
	for (int i = x; i < x+N; i++){
		for (int j = y; j < y+N; j++){
			if (base_num != board[i][j]) return false;
		}
	}
	return true;
}

void DFS(int x, int y, int N){	
	if (find_paper(x, y, board[x][y], N)){
		//print_board(x, y, N);
		answer[board[x][y] + 1]++;
		return;
	}

	int next_N = N / 3;
	for (int j = x; j < x+N; j = j + next_N){
		for (int k = y; k < y+N; k = k + next_N){
			DFS(j, k, next_N);
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("1780.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> board[i][j];
		}
	}
	DFS(1, 1, N);
	for (int i = 0; i < 3; i++){
		cout << answer[i] << endl;
	}
	return 0;
}
