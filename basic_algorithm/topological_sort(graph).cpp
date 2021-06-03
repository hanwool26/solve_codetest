#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	vector<vector<int> > graph(n + 1, vector<int>(n + 1, 0));
	vector<int> degree(n + 1);
	queue<int> Q;

	for (int i = 0; i < m; i++){
		cin >> a > b;
		graph[a][b] = 1; // make graph
		degree[b]++;	 // 진입 차수 입력
	}
	for (int i = 1; i < n; i++){
		if (degree[i] == 0) Q.push(i);	// 진입차수가 없는 노드 큐잉
	}
	while (!Q.empty()){
		int now = Q.front();
		Q.pop();
		cout << now << " ";
		for (int i = 1; i <= n; i++){
			if (graph[now][i] == 1){	// 연결된 노드가 있다면
				degree[i]--;			// 진입차수 감소
				if (degree[i] == 0) Q.push(i);	// 연결된 노드의 진입차수가 없다면 큐잉
			}
		}
	}
	return 0;
}
