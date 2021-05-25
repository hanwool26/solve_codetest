#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

#define INF int(1e9)
int N;
long int graph[1001][1001];
long int origin[1001][1001];
bool visit[1001][1001];

void print_graph() {
	for (int i = 0; i < N; i++) {
		cout.width(4);
		cout << i + 1;
	}
	cout << "\n\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << " | " << graph[i][j];
		}
		cout << endl << "---------------------------" << endl;
	}
}

void init_case() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			graph[i][j] = INF;
		}
	}
}

long int  graph_sum() {
	long int sum = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			sum += graph[i][j];
		}
	}
	return sum;
}

void dfs(int start, int adj, int weight) {
	if (visit[start][adj] == true) return;
	//printf("before: (%d, %d), weight : %d\n", start, adj, weight);

	if (graph[start][adj] > weight) {
		graph[start][adj] = graph[adj][start] = weight;
		weight = graph[adj][start];
		visit[start][adj] = true;
	}

	printf("after: (%d, %d), weight : %d\n", start, adj, graph[adj][start]);
	
	stack <int> s;

	for (int col = 1; col <= N; col++) {
		if (col == adj || col == start) continue;
		if (graph[adj][col] != INF) {
			s.push(col);
			//printf("pushed : %d\n", col);
		}
	}
	visit[start][adj] = true;
	while (!s.empty()) {
		int node = s.top(); s.pop();
		//printf("(%d %d) : %d\n", adj, node, graph[adj][node]);
		dfs(start, node, graph[adj][node] + weight);
	}
	visit[start][adj] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	clock_t start, end;

	start = clock();
	int T;
	freopen("graph_sum1.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init_case();
		int i, j, w;
		cin >> N;
		for (int k = 0; k < N; k++) {
			cin >> i >> j >> w;
			graph[i][j] = graph[j][i] = w;
		}		
		/*
		for (int i = 1; i <= N; i++){
			dfs(i, i, 0);
		}
		*/

		/* Fluyd washall algorithm */
		/*
		for (int k = 1; k <= N; k++){
			for (int i = 1; i <= N; i++){
				for (int j = 1; j <= N; j++){
					if ((graph[i][j] > graph[i][k] + graph[k][j]) && (graph[i][k] != INF && \
						graph[k][j] != INF)){
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
		*/

		long int answer = graph_sum();
		cout << "#" << tc + 1 << " " << answer << endl;
	}
	end = clock();
	cout << "duration : " << (double)(end - start) / CLOCKS_PER_SEC;
}
