#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;
vector <pair<int, int>> v;
bool visit[10];
vector<int> trace;
int answer;
void DFS(int idx, int distance, int cnt) {
	if (visit[idx]) return;
	if (cnt == N-1 && idx == 1) {
		if (answer > distance) {
			answer = distance;
		}
		trace.push_back(idx);
		for (auto& i : trace) {
			cout << i << " ";
		}
		trace.pop_back();
		cout << distance << endl;
		return;
	}
	visit[idx] = true;
	trace.push_back(idx);
	for (int i = 1; i < N; i++) {
		DFS(i, distance + (abs(v[idx].first - v[i].first) + abs(v[idx].second - v[i].second)), cnt+1);
	}
	trace.pop_back();
	visit[idx] = false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;

	freopen("1247.txt", "r", stdin);
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		memset(visit, false, sizeof(visit));
		v.clear();
		answer = (int)1e9;
		cin >> N;
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}

		DFS(0, 0, 0);

		cout << answer << endl;
	}
}
