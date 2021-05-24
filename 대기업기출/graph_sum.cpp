/** TC Example
1
7
1 6 3
6 5 3
5 3 2
5 2 5
2 4 4
2 7 2
**/

#include <iostream>
#include <stack>
using namespace std;

int N;
long int graph[1001][1001];

stack <int> s;

void print_graph(){
	for (int i = 0; i < N; i++){
		cout.width(4);
		cout << i+1;
	}
	cout << "\n\n";
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cout << " | " << graph[i][j];
		}
		cout << endl << "---------------------------" << endl;
	}
}

void init_case() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			graph[i][j] = 0;
		}
	}
}


void dfs(int vertex, int con_vertex, int sum, int visit[]){
	printf("ver : %d con_ver : %d sum : %d\n", vertex, con_vertex, sum);
	
	if (visit[con_vertex] == true) return;
	visit[con_vertex] = true;
	int cur_node = con_vertex;

	graph[vertex][con_vertex] = graph[con_vertex][vertex] = sum;
	for (int col = 0; col <= N; col++){
		if (col == vertex || visit[col] == true) continue;
		if (graph[con_vertex][col] != 0){			
			s.push(col);
			cout << "push : " << col << endl;
		}
	}
	while (!s.empty()){
		con_vertex = s.top(); s.pop();
		dfs(vertex, con_vertex, graph[cur_node][con_vertex]+sum, visit);
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	freopen("graph_sum.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int i, j, w;
		cin >> N;
		for (int k = 0; k < N; k++) {
			cin >> i >> j >> w;
			graph[i][j] = graph[j][i] = w;
		}
		int visit[8];
		memset(visit, false, sizeof(visit));
		dfs(1, 1, 0, visit);

		print_graph();
	}
}
