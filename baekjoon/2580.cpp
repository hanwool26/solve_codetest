#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

typedef struct node{
	int x;
	int y;
	node(int a, int b){
		x = a;
		y = b;
	}
}Node;

int board[9][9];
bool visit[9][9] = { false, };
vector<Node> v;
bool answer = false;

void print_board(){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool check_board(){
	for (int i = 0; i < 9; i++){
		int dp[10] = { 0, };
		for (int j = 0; j < 9; j++){
			if (dp[board[i][j]] == 1) return false;
			dp[board[i][j]] = 1;
		}
	}
	for (int i = 0; i < 9; i++){
		int dp[10] = { 0, };
		for (int j = 0; j < 9; j++){
			if (dp[board[j][i]] == 1) return false;
			dp[board[j][i]] = 1;
		}
	}
	for (int k = 0; k < 3; k++){
		int dp[10] = { 0, };
		for (int i = 3 * k; i < 3 * k + 3; i++){
			for (int j = 3 * k; j < 3 * k + 3; j++){
				if (dp[board[i][j]] == 1) return false;
				dp[board[i][j]] = 1;
			}
		}
	}
	return true;
}

void DFS(int idx){
	if (answer) return;
	if (idx == v.size() && check_board()){
		print_board();
		answer = true;
		return;
	}

	for (int i = 1; i < 10; i++){
		Node n = v[idx];
		int flag = false;
		for (int j = 0; j < 9; j++){
			if (board[n.x][j] == i || board[j][n.y] == i){
				flag = true;
				break;
			}
		}
		if (flag == true) continue;
		board[n.x][n.y] = i;		
		DFS(idx + 1);
		board[n.x][n.y] = 0;
	}
}

int main(){
	clock_t start, end;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	start = clock();
	freopen("2580.txt", "r", stdin);
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			cin >> board[i][j];
			if (board[i][j] == 0){
				v.push_back(Node(i, j));
			}
		}
	}
	//cout << check_board() << endl;
	DFS(0);
	end = clock();

	cout << "duration : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
}
