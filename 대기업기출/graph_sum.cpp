#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

#define MAX 1001
#define INF int(1e9)
int N;
int graph[MAX][MAX];
vector<int> v[MAX];
bool visit[MAX];

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

void dfs(int start, int adj, long int weight) {
	graph[start][adj] = graph[adj][start] = weight;
	int stack_size = v[adj].size();
	visit[adj] = true;
	for (int i = 0; i < stack_size; i++) {
		int next = v[adj][i];
		if (visit[next] == true) continue;
		dfs(start, next, graph[adj][next] + weight);
	}
	visit[adj] = false;
}

int main() {
	clock_t start, end;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;

	start = clock();
	freopen("graph_sum.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int n_i, n_j, w;
		cin >> N;
		//init_case();
		//memset(graph, INF, sizeof(int)*MAX*MAX);
		for (int i = 0; i < N-1; i++) {
			cin >> n_i >> n_j >> w;
			graph[n_i][n_j] = graph[n_j][n_i] = w;
			v[n_i].push_back(n_j); v[n_j].push_back(n_i);
		}

		for (int i = 1; i <= N; i++) {
			visit[i] = true;
			dfs(i, i, 0);
			visit[i] = false;
		}
		//print_graph();
		long int answer = graph_sum();
		cout << "#" << tc + 1 << " " << answer << endl;
		end = clock();
		cout << "duration : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	}
}
