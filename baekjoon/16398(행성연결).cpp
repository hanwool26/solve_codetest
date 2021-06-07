#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

unsigned int graph[1001][1001];
int N;
bool visit[1001];

typedef struct node{
	int adj;
	int dis;
	node(int a, int b){
		adj = a;
		dis = b;
	}
	bool operator<(const node &b)const{
		return dis > b.dis;
	}
}Node;

vector<Node> v[1001];
int answer = int(1e9);

int prim_MST(int node){
	int cnt = 0;
	priority_queue<Node> pq;
	pq.push(Node(node, 0));

	while (!pq.empty()){
		int adj = pq.top().adj;
		int distance = pq.top().dis;
		pq.pop();		
		if (visit[adj] == false){
			cnt += distance;
			visit[adj] = true;
			for (int i = 0; i < v[adj].size(); i++){
				pq.push(Node(v[adj][i].adj, graph[adj][v[adj][i].adj]));
			}
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("16398.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> graph[i][j];
			v[i].push_back(Node(j, graph[i][j]));			
		}
	}

	memset(visit, false, sizeof(visit));		
	answer = prim_MST(1);	
    
	cout << answer << endl;
	return 0;
}
