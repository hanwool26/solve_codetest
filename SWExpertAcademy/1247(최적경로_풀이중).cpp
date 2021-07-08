#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N;
vector <pair<int, int>> v;
bool visit[12];
int dp[12][(1<<12)-1];
int answer;

void DFS(int idx, int use, int distance, int cnt) {
	if (visit[idx]) return;

	if (cnt == N + 1 && idx == 1) {
		if (answer > distance) {
			answer = distance;
		}
		return;
	}	
	if (dp[idx][use] < distance) return;
	else dp[idx][use] = distance;

	visit[idx] = true;
	for (int i = 1; i <= N + 1; i++) {
		DFS(i, use | (1<<i), distance + (abs(v[idx].first - v[i].first) + abs(v[idx].second - v[i].second)), cnt+1);
	}
	visit[idx] = false;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;

	//freopen("1247.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < (1 << 12)-1; j++) {
				dp[i][j] = (int)1e9;
			}
		}		
		v.clear();
		answer = (int)1e9;
		cin >> N;
		for (int i = 0; i < N+2; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		DFS(0, 0, 0, 0);
		cout << "#" << tc << " " << answer << endl;
	}
}
