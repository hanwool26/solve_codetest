#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int unf[1001];

struct Edge{
	int vex;
	int dis;
	Edge(int a, int b){
		vex = a;
		dis = b;
	}
	bool operator<(const Edge &b)const{
		return dis > b.dis;	// 최소 heap 
	}
};

int main(){
	priorty_queue<Edge> Q;
	vector<pair<int,int>> graph[30];
	int i, n, m, a, b, c;
	cin >> n >> m;
	vector<int> dist(n+1, int(ie9));
	for(i=1; i<=m; i++){
		cin >> a,b,c;
		graph[a].push_back(make_pair(b,c));
	}
	Q.push(Edge(1,0);
	dist[1] = 0;
	while(!Q.empty()){
		int now=Q.top().vex; // min heap (간선 최소값이 return) 
		int cost=Q.top().dis;
		Q.pop();
		if(cost>dist[now]) continue;
		for(i=0; i<graph[now].size(); i++){
			int next=graph[now][i].first;
			int nextDis = cost + graph[now][i].second;
			if(dist[next]>nextDis){
				dist[next]=nextDis;
				Q.push(Edge(next, nextDis));
			}
		}
	}
	// dist 값을 0에서의 모든 정점으로의 최소 거리 저장. 
}
		
