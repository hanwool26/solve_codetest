#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef struct pos {
	int x;
	int y;
}Pos;

typedef struct edge {
	int adj;
	long long fee;
	edge(int a, int b) {
		adj = a;
		fee = b;
	}
	bool operator<(const edge &b)const {
		return fee > b.fee;
	}
}Edge;



Pos p[1001];
int N;
double E;
bool visit[1001];

vector<Edge> v[1001];

void print_pos() {
	for (int i = 1; i <= N; i++) {
		printf("(%d %d)\n", p[i].x, p[i].y);
	}
}

long long prim_mst() {
	priority_queue<Edge> q;
	q.push(Edge(1, 0));
	long long answer = 0;
	
	while (!q.empty()) {
		int adj = q.top().adj;
		long long fee = q.top().fee;		
		q.pop();		

		if (visit[adj] == false) {
			answer += fee;
			visit[adj] = true;
			for (int i = 0; i < v[adj].size(); i++) {
				int vertex = v[adj][i].adj;
				q.push(Edge(vertex, v[adj][i].fee));
			}
		}
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;

	freopen("1251.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		memset(visit, false, sizeof(visit));
		for (int i = 0; i <= 1000; i++) {
			v[i].clear();
		}
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> p[i].x;
		}
		for (int i = 1; i <= N; i++) {
			cin >> p[i].y;
		}
		cin >> E;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if(p[i].x == p[j].x) v[i].push_back(Edge(j, E * (long long)((long long)pow(abs(p[i].y - p[j].y), 2))));
				else if (p[i].y == p[j].y) v[i].push_back(Edge(j, E * (long long)((long long)pow(abs(p[i].x - p[j].x), 2))));
				else v[i].push_back(Edge(j, E * (long long)((long long)pow(abs(p[i].x - p[j].x), 2) + (long long)pow(abs(p[i].y - p[j].y), 2))));
			}
		}
		
		cout << "#" << tc << " " << prim_mst() << endl;
	}
}
