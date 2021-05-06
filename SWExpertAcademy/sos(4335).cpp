#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Box{
	int w;
	int h;
	int l;
}Box;
int box[20][3];
int answer = 0;
int T, N, w, h, l;

void print_box(){
	for (int i = 0; i < N; i++){
		cout << box[i][0] << " " << box[i][1] << " " << box[i][2] << endl;
	}
}

int is_below(int idx, int cp_idx){ // cp_idx : compared_idx
	int dp[3] = { 0, };
	int cnt = 0;
	int remain = 0;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (box[idx][i] <= box[cp_idx][j] && dp[j] == 0){
				dp[j] = box[cp_idx][j];
				cnt++;
			}

		}
	}
	if (cnt == 2){
		for (int i = 0; i < 3; i++){
			if (box[cp_idx][i] != dp[0] && box[cp_idx][i] != dp[1])
				remain = box[cp_idx][i];
		}
	}
	if (cnt == 3){
		remain = *max_element(dp, dp + 3);
	}
	cout << "remain : " << remain << endl;
	return remain;
}

void DFS(int idx, int cnt, int sum){
	if (cnt == N) return;
	if (sum > answer) sum = answer; 

	for (int i = 0; i < N; i++){
		if (is_below(idx, i) != 0) continue;
		else {
		}
		}
	}
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("sos_input.txt", "r", stdin);
	cin >> T;

	for (int tc = 0; tc < 2; tc++){
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> w >> h >> l;
			box[i][0] = w;
			box[i][1] = h;
			box[i][2] = l;
		}
		print_box();
		is_below(0, 1);
		cout << "#" << tc+1 << " " << answer << endl;
	}
}
