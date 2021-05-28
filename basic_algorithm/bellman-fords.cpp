// 벨만포드 알고리즘 : 출발점에서 도착점까지 최소 비용을 구하는 알고리즘.
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int dist[101]; 

struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
};

int main(){
	vector<Edge> ed;
	int i,n,m,a,b,c,j,s,e;
	for(i=1; i<=m; i++){
		ed.push_back(Edge(a,b,c));
	}
	
	for(i=1; i<=n; i++){
		dist[i] = int(1e9);
	}
	
	dist[s] = 0;
	for(i=1; i<n; i++){
		for(j=0; j<ed.size(); j++){
			int u = ed[j].s;
			int v = ed[j].e;
			int w = ed[j].val;
			if(dist[u]!=int(1e9) && dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
			}
		}
	}
	for(j=0; j<ed.size(); j++){
		int u = ed[j].s;
		int v = ed[j].e;
		int w = ed[j].val;
		if(dist[u]!=int(1e9) && dist[u]+w<dist[v]){
			printf("-1\n");
			exit(0);
		}
	}
	printf("%d\n", dist[e]);
	return 0;
}
}
		
