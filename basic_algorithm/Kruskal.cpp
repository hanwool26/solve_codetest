# 최소 스패닝 트리. & Union/Find 활용.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int unf[1001];

struct Edge{
	int v1;
	int v2;
	int val;
	Edge(int a, int b, int c){
		v1 = a;
		v2 = b;
		val = c;
	}
	bool operator<(Edge &b){
		return val < b.val;
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a!=b) unf[a] = b;
}

int main(){
	vector<Edge> ed;
	for(int i = 1; i<=N; i++){
		unf[i] = i;
	}
	
	for(i=1; i<=M; i++){
		ed.push_back(Edge(a,b,c));
	}
	sort(ed.begin(), ed.end());
	
	for(i=0; i<M; i++){
		int fa = Find(ed[i].v1);
		int fb = Find(ed[i].v2);
		if(fa!fb){
			res+=ed[i].val;
			Union(ed[i].v1, ed[i].v2);
		}
	}
	return 0;
}
