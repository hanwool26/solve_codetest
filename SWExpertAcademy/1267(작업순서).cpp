#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, E;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("1267.txt", "r", stdin);
	for (int tc = 1; tc <= 10; tc++) {
		cin >> N >> E;
		vector<int> v[1001];
		vector<int> node_in(N + 1, 0);
		queue<int> q;
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			node_in[b]++;
		}

		for (int i = 1; i <= N; i++) {
			if (node_in[i] == 0) {
				q.push(i);
			}
		}
		cout << "#" << tc << " ";

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			cout << node << " ";
			for (int i = 0; i < v[node].size(); i++) {
				int next_adj = v[node][i];
				node_in[next_adj]--;
				if (node_in[next_adj] == 0) {
					q.push(next_adj);
				}
			}
		}
		cout << endl;
	}
}
