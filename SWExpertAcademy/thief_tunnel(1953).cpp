#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int N, M, R, C, L; // R=x pos, C=y pos
int tunnel[50][50];
int visit[50][50];

vector<vector<pair<int, int>>> v{
	{ make_pair(0, 0) },
	{ make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0), make_pair(0, 1) }, // pipe 1
	{ make_pair(-1, 0), make_pair(1, 0) },	// pipe 2
	{ make_pair(0, -1), make_pair(0, 1) },	// pipe 3
	{ make_pair(-1, 0), make_pair(0, 1) },	// pipe 4
	{ make_pair(1, 0),  make_pair(0, 1) },	// pipe 5
	{ make_pair(0, -1), make_pair(1, 0) },	// pipe 6
	{ make_pair(1, 0),  make_pair(0, -1) }	// pipe 7
	};

queue<pair<int, int>> q;

void BFS(int start_x, int start_y){
	q.push(make_pair(start_x, start_y));
	pair<int, int> node;

	while (!q.empty()){
		node = q.front();
		q.pop();
		cout << node.first << " " << node.second << endl;
		if
	}
}

int main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("thief_tunnel_input.txt", "r", stdin);
	cin >> T;
	
	for (int tc = 0; tc < T; tc++){
		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				cin >> tunnel[i][j];
			}
		}
		BFS(R, C);

	}
}
