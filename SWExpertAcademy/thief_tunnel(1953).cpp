#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int N, M, R, C, L; // R=x pos, C=y pos
int tunnel[50][50];
int visit[50][50];

void init_case(){
	for (int i = 0; i < 50; i++){
		for (int j = 0; j < 50; j++){
			tunnel[i][j] = visit[i][j] = 0;
		}
	}
}

vector<vector<pair<int, int>>> v{
	{ make_pair(0, 0) },
	{ make_pair(-1, 0), make_pair(0, -1), make_pair(1, 0), make_pair(0, 1) }, // pipe 1
	{ make_pair(-1, 0), make_pair(1, 0) },	// pipe 2
	{ make_pair(0, -1), make_pair(0, 1) },	// pipe 3
	{ make_pair(-1, 0), make_pair(0, 1) },	// pipe 4
	{ make_pair(1, 0),  make_pair(0, 1) },	// pipe 5
	{ make_pair(1, 0), make_pair(0, -1) },	// pipe 6
	{ make_pair(-1, 0),  make_pair(0, -1) }	// pipe 7
};

int BFS(int start_x, int start_y){
	queue<pair<int, int>> q;
	pair<int, int> node;
	int cnt = 0;
	int period = 1;
	int time = 1;
	int answer = 0;
	q.push(make_pair(start_x, start_y));
	visit[start_x][start_y] = 1;

	while (!q.empty()){
		if (time == L) break;		
		int next_x, next_y;
		node = q.front();
		int pipe = tunnel[node.first][node.second];
		q.pop();
		cnt++;
		for (int i = 0; i < v[pipe].size(); i++){
			next_x = node.first + v[pipe][i].first;
			next_y = node.second + v[pipe][i].second;

			int next_pipe = tunnel[next_x][next_y];
			if (next_x < 0 || next_x > N-1 || next_y < 0 || next_y > M-1 || next_pipe == 0) continue;
				
			for (int j = 0; j < v[next_pipe].size(); j++){
				int dir_x = v[next_pipe][j].first;
				int dir_y = v[next_pipe][j].second;

				if (visit[next_x][next_y] != 1){
					if ((v[pipe][i].first + dir_x == 0 && v[pipe][i].first != 0 && dir_x != 0) ||
								(v[pipe][i].second + dir_y == 0 && v[pipe][i].second != 0 && dir_y != 0)){
						q.push(make_pair(next_x, next_y));
						visit[next_x][next_y] = 1;
						answer++;
					}
				}
			}
		}		
		if (period == cnt){
			queue<pair<int, int>> q_copy = q;
			time++;			
			period = q.size();
			cnt = 0;
		}
	}
	return answer;
}

int main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("thief_tunnel_input.txt", "r", stdin);
	cin >> T;
	
	for (int tc = 0; tc < T; tc++){
		init_case();

		cin >> N >> M >> R >> C >> L;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				cin >> tunnel[i][j];
			}
		}		
		cout << "#" << tc+1 << " " << BFS(R, C)+1 << endl;
	}
}
