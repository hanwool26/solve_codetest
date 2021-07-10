#include <iostream>
#include <vector>
using namespace std;

int N, answer, cnt;


int weight[11];

int visit[9][(1 << 9) - 1][(1 << 9) - 1];
vector<int> l;
vector<int> r;

int cnt_=0;

int DFS(int idx, int l_bit, int r_bit, int l_weight, int r_weight){

	if (l_weight < r_weight) return 0;

	if (idx == N) {
		return 1;
	}
	int &sol = visit[idx][l_bit][r_bit];
	if (sol != -1) return sol;
	sol = 0;
	for (int i = 0; i < N; i++){
		if ((r_bit & (1 << i)) || (l_bit & (1 << i))) continue;
		sol = sol + DFS(idx + 1, l_bit | (1 << i), r_bit, l_weight + weight[i], r_weight);	
		sol = sol + DFS(idx + 1, l_bit, r_bit | (1 << i), l_weight, r_weight + weight[i]);	
	}
	return sol;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("3234.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N;
		answer = 0;
		memset(visit, -1, sizeof(visit));
		for (int i = 0; i < N; i++){
			cin >> weight[i];
		}
		answer = DFS(0, 0, 0,0, 0);
		cout << "#" << tc << " " << answer << endl;
	}
	return 0;
}
