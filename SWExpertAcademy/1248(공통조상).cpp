#include <iostream>
#include <vector>
using namespace std;

int V, E, v1, v2;

vector<int> V1[10001];
vector<int> V2[10001];
bool visit[10001];
int  cnt = 0;

void DFS(int node){
	int size = V1[node].size();
	cnt++;
	visit[node] = true;
	for (int i = 0; i < size; i++){
		DFS(V1[node][i]);
	}
	visit[node] = false;
}

int find_root(){	
	int v1_root = V2[v1][0];
	int v2_root = V2[v2][0];
	int v2_origin = v2_root;

	while (v1_root!=1){
		v1_root = V2[v1_root][0];
		while (v2_root != 1){
			if (v1_root == v2_root){
				return v1_root;
			}
			v2_root = V2[v2_root][0];
		}
		v2_root = v2_origin;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("1248.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> V >> E >> v1 >> v2;
		cnt = 0;
		for (int i = 0; i <= 10001; i++){
			V1[i].clear();
			V2[i].clear();
		}
		for (int i = 0; i < E; i++){
			int a, b;
			cin >> a >> b;
			V1[a].push_back(b);
			V2[b].push_back(a);
		}
		
		int root = find_root();
		DFS(root);
		cout << "#" << tc << " " << root << " " << cnt << endl;
	}
	return 0;
}
