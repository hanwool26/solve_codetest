#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M, answer;
int map_c[20][20];

int dir_x[] = { -1, 1, 0, 0 };
int dir_y[] = { 0, 0, -1, 1 };

int cur_x, cur_y;

void BFS(int x, int y){
	queue<pair<int, int>> q;
	
	int visit[20][20] = {0,}; // 초기화 제대로 할 것!!!!!!!!!!!!
	
	int service_num = 0;
	int depth = 0;
	int K = 0;
	int fee = 0;

	q.push(make_pair(x, y));
	visit[x][y] = 1;	

	while (!q.empty()){
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();
		if (depth != 0) depth--; 
		if (map_c[cur_x][cur_y] == 1){
			service_num++;
		}
		
		for (int i = 0; i < 4; i++){
			int next_x = cur_x + dir_x[i];
			int next_y = cur_y + dir_y[i];
			

			if (next_x < 0 || next_x > N - 1 || next_y <0 || next_y > N - 1 || visit[next_x][next_y]==1) continue;
			q.push(make_pair(next_x, next_y));
			visit[next_x][next_y] = 1;
		}
		if (depth == 0){
			K++;
			fee = service_num*M - (K*K + (K - 1)*(K - 1));
			if (fee >= 0){                
				if (answer < service_num) answer = service_num;                
			}
			depth = q.size();
		}
	}
}

int main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//freopen("safety_home.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++){
		cin >> N >> M;
		answer = 0;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map_c[i][j];
			}
		}	
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				BFS(i, j);
			}
		}
		cout << "#" << tc + 1 << " " << answer << endl;
	}
}
