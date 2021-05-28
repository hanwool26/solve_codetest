#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int unf[1001];

struct Edge{
	int  e;
	int val;
	Edge(int a, int b, ){
		e = a;
		val = c;
	}
	bool operator<(const Edge &b)const{
		return val > b.val;	// 최소 heap 
	}
};

int main(){
	priorty_queue<Edge> Q;
	vector<pair<int, int>> map[30];
	for(i=1; i<=m; i++){	// m is the number of edges.
		map[a].push_back(make_pair(b,c));
		map[b].push_back(make_pair(a,c));
	}
	
	Q.push(Edge(1,0));
	while(!Q.empty()){
		Edge tmp = Q.top();
		Q.pop();
		
		int v = temp.e;
		int cot = tmp.val;
		if(ch[v]==0){
			answer += cost;
			ch[v] =1;
			for(i=0; i<map[v].size(); i++){
				Q.push(Edge(map[v][i].first, map[v][i].second));
			}
		}
		return 0;
	}
}
		
