#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer;

typedef struct player {
	int white;
	int black;
	player(int white, int black) {
		this->white = white;
		this->black = black;
	}
}Player;

vector<Player> v;

void dfs(int idx, int w_sum, int b_sum, int w) {
	if (idx == N) {
		if (w == N - w) {
			answer = min(answer, abs(w_sum - b_sum));
		}		
		return;
	}
	dfs(idx + 1, w_sum + v[idx].white, b_sum, w+1);
	dfs(idx + 1, w_sum, v[idx].black + b_sum, w);
	
}
int main() {
	freopen("바둑대회.txt", "r", stdin);
	int w, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> w >> b;
		v.push_back(Player(w, b));
	}
	answer = 1e9;
	dfs(0, 0, 0,0);
	cout << answer << endl;
	return 0;
}
