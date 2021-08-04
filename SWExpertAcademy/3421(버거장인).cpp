#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, M;
int pair_arr[21];
int answer;

void DFS(int idx, int use, int cnt){
	if (cnt > N + 1) return;
	answer++;
	for (int i = idx; i <= N; i++){
		if (pair_arr[i] & use) continue;
		DFS(i + 1, use | (1 << i), cnt+1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("3421.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N >> M;
		answer = 0;
		memset(pair_arr, 0, sizeof(pair_arr));
		for (int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			pair_arr[a] |= (1 << b);
			pair_arr[b] |= (1 << a);
		}
		DFS(1, 0, 0);
		cout << "#" << tc << " " << answer << endl;
	}
}
