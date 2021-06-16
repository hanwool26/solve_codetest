#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int answer;
int N, W;

enum{
	NONE,
	HEIGHT,
	WIDTH
};

typedef struct box{
	int height;
	int width;
	int weight;
}Box;

Box b[101];
int dp[101][10001][3];
int max_height, max_width, max_value;

void print_box(){
	for (int i = 1; i <= N; i++){
		cout << b[i].height << " " << b[i].width << " " << b[i].weight << endl;
	}
}

void DFS(int idx, int width, int weight, int dir){
	if (idx > N+1 || width > W) return;
	if (width == W){
		answer = max(answer, weight);
		return;
	}
	if (dp[idx][width][dir] >= weight) return;
	dp[idx][width][dir] = weight;
	
	DFS(idx + 1, width + b[idx].width, weight + b[idx].weight, WIDTH);
	DFS(idx + 1, width + b[idx].height, weight + b[idx].weight, HEIGHT);
	DFS(idx + 1, width, weight, NONE);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	clock_t start, end;

	start = clock();
	freopen("complete_load.txt", "r", stdin);
	int T;

	cin >> T;
	for (int tc = 0; tc < T; tc++){
		cin >> N >> W;
		answer = 0;
		max_height = 0;
		max_width = 0;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= N; i++){
			cin >> b[i].height >> b[i].width;
			b[i].weight = b[i].height * b[i].width;
		}
		DFS(0, 0, 0, 0);
		cout << "#" << tc + 1 << " " << answer << endl;
	}
	end = clock();
	cout << "duration: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
