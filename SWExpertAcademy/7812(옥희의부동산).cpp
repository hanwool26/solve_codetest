#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long answer;
int arr[10000];

void DFS(int idx, int money){
	if (money > M || idx > N) return;
	if (money == M) {
		answer++;
		return;
	}
	DFS(idx + 1, money + arr[idx]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("7812.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N >> M;
		answer = 0;
		for (int i = 0; i < N; i++){
			cin >> arr[i];
		}
		for (int i = 0; i < N; i++){
			DFS(i, 0);
		}
		cout << "#" << tc << " " << answer << endl;
	}
}
