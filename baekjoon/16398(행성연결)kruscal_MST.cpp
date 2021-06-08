#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int unf[1001];
int graph[1001][1001];
int N;
long long answer = 0;

struct Edge {
	int v1;
	int v2;
	int val;
	Edge(int a, int b, int c) {
		v1 = a;
		v2 = b;
		val = c;
	}
	bool operator<(const Edge& b)const {
		return val < b.val;
	}
};

int Find(int v) {
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

int Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b) return 0;
	unf[a] = b;
	return 1;
}

int main() {
	vector<Edge> ed;
	//freopen("16398.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		unf[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> graph[i][j];
			if (i<j) ed.push_back(Edge(i, j, graph[i][j]));
		}
	}
	sort(ed.begin(), ed.end());

	for (int i = 0; i < ed.size(); i++) {
		Edge k = ed[i];
		if (Union(k.v1, k.v2)) {
			answer += k.val;
		}
	}
	cout << answer << endl;
	return 0;
}
