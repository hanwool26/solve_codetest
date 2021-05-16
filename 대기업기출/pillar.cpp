/*
"기둥 위에 선반 올리기"
선반을 올리기 위해 양쪽 기둥이 동일해야함
N개의 기둥의 높이가 주어지는데 기둥을 합쳐서 높이가 최대가 되는 기둥 2개를 구하고, 최대 높이값을 구하는 문제
단, 사용하지 않는 기둥이 존재할 수가 있음
높이가 같은 기둥을 만들수 없는 경우 0을 출력

기둥 개수 : 5 <= N <= 50
기둥 길이 : 1 <= K <= 100
기둥 높이 합의 최대값이 1000을 넘지 않음

입력 : 첫째줄에 기둥 N개
두번째줄에 기둥의 높이
기둥의 높이는 정렬되어 있지 않음

출력 : 기둥 높이 최댓값

TC
5 
1 2 4 3 6

답
8
*/

#include <iostream>
using namespace std;

int N;
int pillar[50];
int visit[50];

int answer;
int MAX = 0;

int line_num = 0;

enum FLAG{
	LEFT,
	RIGHT
};

int dp[1000][2];
int use_dp[10][(1 << 20)-1][2];

void DFS(int index, int sum_l, int sum_r, int use, int flag){

	if ((sum_l == MAX || sum_r == MAX)) return;

	if (use_dp[index][use][LEFT] > sum_l && use_dp[index][use][RIGHT] > sum_r) return;
	else use_dp[index][use][flag] = flag == LEFT ? sum_l : sum_r;

	if (sum_l == sum_r && index!=0){
		if (answer < sum_l){
			for (int i = 0; i < N; i++){
				if (visit[i] == 1) cout << pillar[i] << " ";
			}
			cout << endl;
			answer = sum_l;
			return;
		}		
	}
	line_num++;
	visit[index] = 1;
	for (int i = 0; i < N; i++){
		if (visit[i] == 1) continue;
		DFS(i, sum_l + pillar[i], sum_r, use | (1 << i), LEFT);
		DFS(i, sum_l, sum_r + pillar[i], use | (1 << i), RIGHT);
	}
	visit[index] = 0;
}

int main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("pillar_input.txt", "r", stdin);
	cin >> T;

	for (int tc = 0; tc < T; tc++){
		cin >> N;
		answer = 0;
		for (int i = 0; i < N; i++){
			
			cin >> pillar[i];
			MAX += pillar[i];
		}
		cout << "max" << MAX << endl;
		DFS(0, pillar[0],0, 0, LEFT);
		DFS(0, 0, pillar[0], 0, RIGHT);
		cout << "#" << tc + 1 << " " << answer << " " << line_num << endl;
	}
}
