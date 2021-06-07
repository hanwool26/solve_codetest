#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int graph[51][51];
bool visit[51];
vector<int> v[51];
#define INF int(1e9)
int N;

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

void dfs(int start, int adj, int cnt){
	if (graph[start][adj] > cnt)
		graph[start][adj] = graph[adj][start] = cnt;

    int size = v[adj].size();
	for (int i = 0; i < size; i++){
		int next = v[adj][i];
		if (visit[next] == true) continue;
		visit[adj] = true;
		dfs(start, next, graph[adj][next] + cnt);
		visit[adj] = false;
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;

	//freopen("2660.txt", "r", stdin);
	cin >> N;
	
	for (int i = 1; i <= 50; i++){
		for (int j = 1; j <= 50; j++){
			graph[i][j] = INF;
		}
	}
	while (true){
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		graph[a][b] = graph[b][a] = 1;
		v[a].push_back(b); v[b].push_back(a);

	}

	for (int i = 1; i <= N; i++){
		visit[i] = true;
		dfs(i, i, 0);
		visit[i] = false;

	}	
	/*
	for (int k = 1; k <= N; k++){
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (i == j) graph[i][j] = 0;
				if (graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}
	*/
	int min = int(1e9);
	int candiate[51];
	int cnt = 0;
	int ans[51];
	for (int i = 1; i <= N; i++){
		int max = 0;
		for (int j = 1; j <= N; j++){
			if (max < graph[i][j]) max = graph[i][j];
		}
		candiate[i] = max;
		if (min > max) min = max;
	}

	for (int i = 1; i <= N; i++){
		if (candiate[i] == min){
			ans[cnt++] = i;
		}
	}
	cout << min << " " << cnt << endl;
	for (int i = 0; i < cnt; i++){
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
