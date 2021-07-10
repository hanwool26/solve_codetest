#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H;	// 세로, 가로선, 가로

bool visit[31][11];
int answer = int(1e9);

bool check(){	
	//cout << "check" << endl;
	for (int i = 1; i <= N; i++){
		int cur = i;
		for (int j = 1; j <= H; j++){
			if (visit[j][cur] == true) cur = cur + 1;
			else if (visit[j][cur - 1] == true) cur = cur - 1;
		}
		if (cur != i) return false;
	}
	return true;
}

void DFS(int idx, int cnt){
	if (cnt >= 4) return;
	if (check()==true){
		//cout << "check" << endl;
		answer = min(answer, cnt);
		return;
	}

	for (int i = idx; i <= H; i++){
		for (int j = 1; j <= N; j++){
			if (visit[i][j] == true) continue;
			if (visit[i][j - 1] == true) continue;
			if (visit[i][j + 1] == true) continue;
			visit[i][j] = true;
			DFS(i, cnt + 1);
			visit[i][j] = false;
		}
	}	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	//freopen("15684.txt", "r", stdin);
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++){
		cin >> a >> b;
		visit[a][b] = true;
	}

	DFS(1, 0);
	cout << ((answer!=int(1e9))?answer:-1) << endl;
}
