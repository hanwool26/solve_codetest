#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

typedef struct node {
	int v;
	int dis;
}Node;

vector<Node> graph[100001];
vector<Node> r_graph[100001];

int solution(int height, vector<vector<int>> path, vector<int> signs) {
	int answer = 0;
	queue<Node> q;
	unordered_set<int> sign_set;

	for (int i = 0; i < path.size(); i++) {
		graph[path[i][0]].push_back({ i + 2, path[i][1] });
		r_graph[i + 2].push_back({ path[i][0], path[i][1] });
	}

	r_graph[1].push_back({ 0, 0 });	// 1 지점에도 넣어줌. 

	for (auto &k : signs){
		sign_set.insert(height - k);
	}
	q.push({ 1, 0 });

	while (!q.empty()){
		Node n = q.front();
		int sv = n.v;
		int dis = n.dis;
		q.pop();
		
		for (int i = 0; i < r_graph[sv].size(); i++){
			cout << sv << " " <<  dis << endl;
			for (auto &sign_v : sign_set){
				cout << "[debug] s : " << sign_v << " " << dis - r_graph[sv][i].dis << " ~ " << dis << endl;
				if ((sign_v < dis && sign_v > dis - r_graph[sv][i].dis) || sign_v == dis){
					answer++;
				}
			}
		}

		for (int i = 0; i < graph[sv].size(); i++) {
			int next_v = graph[sv][i].v;
			int next_dis = graph[sv][i].dis;
			q.push({ next_v, dis + next_dis });
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> path = { { 1, 2 }, { 3, 3 }, { 2, 4 }, { 3, 5 }, { 1, 4 }, { 6, 7 }, { 4, 4 }, { 4, 4 }, { 12, 7 }, { 12, 7 }, { 1, 3 } };
	vector<int> signs = { 2, 8, 10 };
	int height = 10;

	cout << solution(10, path, signs) << endl;
	system("pause");
	return 0;
}
