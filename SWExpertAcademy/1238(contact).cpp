#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef struct node {
	int adj;
	int time;
	node(int a, int b) {
		adj = a;
		time = b;
	}
}Node;

vector<Node> v[101];
int time_memo[101];
int answer = 0;
int N, S;

void BFS(int start) {
	queue<Node> q;
	q.push(Node(start, 0));
	bool visit[101];
	memset(visit, false, sizeof(visit));

	int save_time = 0;
	answer = -1;
	visit[start] = true;

	while (!q.empty()) {
		int adj = q.front().adj;
		int time = q.front().time;
		q.pop();

		time_memo[adj] = time;

		for (int i = 0; i < v[adj].size(); i++) {
			int next_adj = v[adj][i].adj;
			if (visit[next_adj] == true) continue;
			q.push(Node(next_adj, time + 1));
			visit[next_adj] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int tc = 1; tc <= 10; tc++) {
		for (int i = 0; i < 101; i++) {
			v[i].clear();
		}
		memset(time_memo, 0, sizeof(time_memo));
		
		cin >> N >> S;
		int edge_num = N / 2;
		for (int i = 0; i < edge_num; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(Node(b,0));
		}		
		BFS(S);
		int temp = 0;
		for (int i = 100; i >= 0; i--) {
			if (temp < time_memo[i]) {
				temp = time_memo[i];
				answer = i;
			}
		}		
		cout << "#" << tc << " " << answer << endl;
	}
}
