#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int map[17][17];

bool visit[17];
int answer = 0;

void DFS(int idx, int cnt, int distance){
	
	if (cnt > N-1 || visit[idx]) return;
	if (cnt == N-1){
		answer = min(answer, distance+map[idx][1]);
		return;
	}

	visit[idx] = true;
	for (int i = 2; i <= N; i++){
		DFS(i, cnt + 1, distance + map[idx][i]);	
	}
	visit[idx] = false;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("5265.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N;
		answer = (int)1e9;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				cin >> map[i][j];
			}
		}
		DFS(1, 0, 0);
		cout << "#" << tc << " " << answer << endl;
	}
}
