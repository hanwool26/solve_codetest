#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B;
vector<int> arr;
int answer;

void DFS(int idx, int cnt) {
	//if (idx > N) return;
	if (idx == N){
		if (cnt >= B) {
			answer = min(answer, (cnt - B));
		}
		return;
	}

	DFS(idx + 1, cnt + arr[idx]);
	DFS(idx + 1, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("high_shelf.txt", "r", stdin);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> B;
        arr.clear();
		answer = (int)1e9;
		for (int i = 0; i < N; i++) {
			int temp;
			cin >> temp;
			arr.push_back(temp);
		}
		DFS(0, 0);
		cout << "#" << tc << " " << answer << endl;
	}
}
