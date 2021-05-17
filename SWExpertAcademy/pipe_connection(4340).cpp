#include <iostream>
using namespace std;

int N;
int pillar[50];
int visit[50];
int answer;
int MAX = 0;

enum FLAG{
	LEFT,
	RIGHT
};

int use_dp[10][(1 << 20)-1][2];

void DFS(int index, int sum_l, int sum_r, int use, int flag){

	if ((sum_l == MAX || sum_r == MAX)) return;	
	if (use_dp[index][use][LEFT] > sum_l && use_dp[index][use][RIGHT] > sum_r) return;	
	if (sum_l == sum_r && index!=0){
		if (answer < sum_l){
			answer = sum_l;			
			return;
		}		
	}
	visit[index] = 1;
	use_dp[index][use][flag] = flag == LEFT ? sum_l : sum_r;

	for (int i = 0; i < N; i++){
		if (visit[i] == 1) continue;
		if (sum_l < sum_r)
			DFS(i, sum_l + pillar[i], sum_r, use | (1 << i), LEFT);
		else
			DFS(i, sum_l, sum_r + pillar[i], use | (1 << i), RIGHT);
	}
	visit[index] = 0;
}

int main()
{
	int T;
	ios::sync_with_stdio(false);

	freopen("pillar_input.txt", "r", stdin);
	cin >> T;

	for (int tc = 0; tc < T; tc++){
		cin >> N;
		answer = 0;
		for (int i = 0; i < N; i++){

			cin >> pillar[i];
			MAX += pillar[i];
		}
		DFS(0, pillar[0],0, 0, LEFT);
		cout << "#" << tc + 1 << " " << answer << " " << endl;
	}
}
