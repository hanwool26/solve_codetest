/*
10
1 7 12
4 7 20
2 4 21
1 4 23
1 2 26
3 5 29
5 6 30
2 3 36
3 6 37
2 5 45
3 7 55
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
	int e;		// end
	int dis;	// distance
	edge(int e, int dis) {
		this->e = e;
		this->dis = dis;
	}
	bool operator<(const edge& e) const{
		return this->dis > e.dis;
	}
}Edge;

bool visit[10];

int main() {
	vector<Edge> graph[10];

	freopen("다익스트라.txt", "r", stdin);
	int N; cin >> N;
	int s, e, dis;
	for (int i = 0; i < N; i++) {
		cin >> s >> e >> dis;
		graph[s].push_back(Edge(e, dis));
		graph[e].push_back(Edge(s, dis));
	}
	memset(visit, false, sizeof(visit));
	priority_queue<Edge> pq;

	pq.push(Edge(1, 0));
	int res = 0;	

	while (!pq.empty()) {
		int e = pq.top().e;
		int dis = pq.top().dis;
		pq.pop();

		if (visit[e] != true) {
			res += dis;
			visit[e] = true;
			for (int i = 0; i < graph[e].size(); i++) {
				int next = graph[e][i].e;
				int next_dis = graph[e][i].dis;
				pq.push(Edge(next, next_dis));
			}
		}		
	}
	cout << res << endl; // 148
	return 0;	
}	
