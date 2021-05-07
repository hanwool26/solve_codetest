#include <iostream>

using namespace std;

#define MAX_N 8
int N, K, answer, max_val, max_size;// 3<=N<=8, 1<=K<=5
int trail[MAX_N][MAX_N];
struct pos{
	int x;
	int y;
};
struct pos start[5];
bool visit[MAX_N][MAX_N];

void init_case(){
	for (int i = 0; i < MAX_N; i++){
		for (int j = 0; j < MAX_N; j++){
			trail[i][j] = visit[i][j]= 0;			
		}
	}
	for (int i = 0; i < 5; i++){
		start[i].x = start[i].y = 0;
	}
	max_val = answer = max_size = 0;
}

int find_top(){
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (trail[i][j] == max_val){
				start[cnt++] = { i, j };
			}
		}
	}
	return cnt;
}

void DFS(int x, int y, int height, int distance, bool desc){
	if (visit[x][y] == true) return;
	
	if (answer < distance){
		answer = distance;
	}

	visit[x][y] = true;
	if (x-1 >= 0 && height > trail[x-1][y]){
		DFS(x-1, y, trail[x-1][y], distance + 1, desc);
	}
	else if (x-1 >= 0 && height <= trail[x-1][y]){
		for (int i = 1; i <= K; i++){
			if (desc!=true && (height > (trail[x-1][y]-i))){
				DFS(x-1, y, (trail[x-1][y]-i < 0 ? 0 : (trail[x-1][y]-i)), distance + 1, true);
			}
		}
	}
	if (x+1 < N && height > trail[x+1][y]){
		DFS(x+1, y, trail[x+1][y], distance + 1, desc);
	}
	else if (x+1 < N && height <= trail[x+1][y]){
		for (int i = 1; i <= K; i++){
			if (desc != true && (height >(trail[x+1][y] - i))){
				DFS(x+1, y, (trail[x+1][y]-i < 0 ? 0 : (trail[x+1][y]-i)), distance + 1, true);
			}
		}
	}
	if (y-1 >= 0 && height > trail[x][y-1]){
		DFS(x, y-1, trail[x][y-1], distance + 1, desc);
	}
	else if (y-1 >= 0 && height <= trail[x][y-1]){
		for (int i = 1; i <= K; i++){
			if (desc != true && (height >(trail[x][y-1] - i))){
				DFS(x, y-1, (trail[x][y-1]-i < 0 ? 0 : (trail[x][y-1] - i)), distance + 1, true);
			}
		}
	}
	if (y+1 < N && height > trail[x][y+1]){
		DFS(x, y+1, trail[x][y+1], distance + 1, desc);
	}
	else if (y+1 < N && height <= trail[x][y+1]){
		for (int i = 1; i <= K; i++){
			if (desc != true && (height >(trail[x][y+1]-i))){
				DFS(x, y+1, (trail[x][y+1]-i < 0 ? 0 : (trail[x][y+1]-i)), distance + 1, true);
			}
		}
	}
	visit[x][y] = false;
	return;
}

int main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    cin >> T;
	for (int tc = 0; tc < T; tc++){
		int top_size;
		init_case();
		cin >> N >> K;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> trail[i][j];
				if (max_val < trail[i][j]) max_val = trail[i][j];
			}
		}
		top_size = find_top();

		for (int i = 0; i < top_size; i++){
			DFS(start[i].x, start[i].y, max_val, 1, false);
		}		
		cout << "#" << tc + 1 << " " << answer << endl;
	}
}
