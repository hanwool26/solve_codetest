#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <time.h>
using namespace std;

char map[20][20];
int C, R;

typedef struct node {
	int x;
	int y;
	int depth;
	node(int a, int b, int c) {
		x = a;
		y = b;
		depth = c;
	}
}Node;

typedef struct edge {
	int adj;
	int dis;
	edge(int a, int b) {
		adj = a;
		dis = b;
	}
	bool operator<(const edge& b)const {
		return dis > b.dis;
	}
}Edge;

Node start(Node(0, 0, 0));
vector<Node> dv; // dirty vector
int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

int start_idx;
int graph[20][20];

vector<Edge> de[100];

void print_graph() {
	for (int i = 0; i < dv.size(); i++) {
		for (int j = 0; j < dv.size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void make_graph() {
	queue<Node> q;
	int visit[20][20];
	for (int i = 0; i < dv.size(); i++) {
		memset(visit, false, sizeof(visit));
		q.push(Node(dv[i].x, dv[i].y, dv[i].depth));
		visit[dv[i].x][dv[i].y] = true;
		if (dv[i].x == start.x && dv[i].y == start.y) start_idx = i;
		while (!q.empty()) {
			Node temp = q.front();
			q.pop();
			int x = temp.x;
			int y = temp.y;
			int depth = temp.depth;
			for (int k = 0; k < dv.size(); k++) {
				
				if (x == dv[k].x && y == dv[k].y) {
					
					de[i].push_back(Edge(k, depth));
					graph[i][k] = depth;
				}
			}
			for (int i = 0; i < dv.size(); i++) {
				int nx = x + dir_x[i];
				int ny = y + dir_y[i];
				if (nx < 0 || nx > R - 1 || ny < 0 || ny > C - 1 || visit[nx][ny] || map[nx][ny] == 'x') continue;
				q.push(Node(nx, ny, depth + 1));
				visit[nx][ny] = true;
			}
		}
	}
}


int answer;
bool visit[10];

void DFS(int idx, int dis, int cnt) {
	
	if (dis > answer || idx > dv.size()) return;
	if (cnt == dv.size()) {
		answer = min(answer, dis);
		return;
	}
	for (int i = 0; i < dv.size(); i++) {
		if (visit[i]) continue;
		visit[i] = true;
		DFS(i, dis + graph[idx][i], cnt + 1);
		visit[i] = false;
	}
}

int prim_mst() {
	int de_size = de[0].size();
	if (de_size != dv.size()) return -1;
	int answer = 0;
	bool visit[10];
	memset(visit, false, sizeof(visit));
	priority_queue<Edge> pq;

	pq.push(Edge(0, 0));

	while (!pq.empty()) {
		Edge temp = pq.top();
		pq.pop();
		int adj = temp.adj;
		int dis = temp.dis;
		if (visit[adj] != true) {
			visit[adj] = true;
			answer += dis;
			while (!pq.empty()) pq.pop();
			for (int i = 0; i < de[adj].size(); i++) {

				int next = de[adj][i].adj;
				int n_next = de[adj][i].dis;
				pq.push(Edge(next, n_next));
			}
		}
	}
	for (int i = 0; i < de_size; i++) {
		de[i].clear();
	}
	return answer;
}

int main() {
	clock_t start_t, end_t;
	start_t = clock();
	//freopen("4991.txt", "r", stdin);
	while (true) {
		cin >> C >> R;
		if (C == 0 && R == 0) break;
		dv.clear();
		for (int i = 0; i < 100; i++) {
			de[i].clear();
		}
		for (int i = 0; i < R; i++) {
			char temp[100];
			cin >> temp;
			for (int j = 0; j < strlen(temp); j++) {
				map[i][j] = temp[j];
				if (map[i][j] == 'o') {
					start.x = i;
					start.y = j;
				}
				if (map[i][j] == '*' || map[i][j] == 'o') {
					dv.push_back(Node(i, j, 0));
				}
			}
		}
		make_graph();
		//print_graph();
		//int answer = prim_mst();
		memset(visit, false, sizeof(visit));
		answer = (int)1e9;

		DFS(start_idx, 0, 0);
		
		int de_size = de[0].size();
		if (de_size != dv.size()) answer = -1;
		for (int i = 0; i < de_size; i++) {
			de[i].clear();
		}

		cout << answer << endl;
		end_t = clock();
	}
	//cout << "duration : " << (double)(end_t - start_t) / CLOCKS_PER_SEC << endl;
}
