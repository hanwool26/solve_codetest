#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[] = {{1,2},{2,3},{3,4}};

void dfs(vector<int> graph[], int start, vector<bool> &visit){
	cout << start << endl;
	visit[start] = true;
	
	for(auto &i: graph[start]){
		if(visit[i]!=true){
			visit[i] = true;
			dfs(graph, i, visit);
		}
	}	
}

void bfs(vector<int> graph[], int start, vector<bool> visit){
	queue<int> q;
	q.push(start);
	visit[start] = true;
	
	while(!q.empty()){
		start = q.front();
		cout << start << " ";
		q.pop();
		/*
		for(int i=0; i < graph[start].size(); i++){
			
			if(!visit[graph[start][i]]){
				q.push(graph[start][i]);
				visit[graph[start][i]] = true;
			}
		}
		*/
		for(auto &i:graph[start]){
			if(!visit[i]){
				q.push(i);
				visit[i] = true;
			}
		}
	}
}

int main(void){
	//bool visit[4] = { false,};
	vector<bool> visit(4,false);
	bfs(a, 0, visit);
}
