// https://swblossom.tistory.com/51
/*
7
1 2 4
1 3 2
2 4 4
2 5 5
3 5 4
4 6 1
5 6 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node {
	int s;
	int e;
	int dis;
	node(int s, int e, int dis) {
		this->s = s;
		this->e = e;
		this->dis = dis;
	}
	bool operator<(node& b) {
		return this->dis < b.dis;
	}
}Node;

int parent[100];
int N, res;
vector<Node> v;

void init() {
	res = 0;
	for (int i = 0; i < 100; i++) {
		parent[i] = i;
	}
}

int Find(int x) {
	if (parent[x] == x) return x;
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
		parent[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("다익스트라.txt", "r", stdin);
	cin >> N;
	int s, e, dis;

	init();
	for (int i = 0; i < N; i++) {
		cin >> s >> e >> dis;
		v.push_back(Node(s, e, dis));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		Node n = v[i];

		int ed_s = Find(n.s);
		int ed_e = Find(n.e);
		if (ed_s != ed_e) {
			res += n.dis;
			parent[ed_s] = ed_e;
		}
	}
	cout << res << endl;
	return 0;
}
