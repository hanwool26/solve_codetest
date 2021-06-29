#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000001
long long dp[MAX];
long long city[MAX];
int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("9780.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N;
		for (int i = 1; i <= N; i++){
			cin >> city[i];
		}
		dp[1] = city[1];
		dp[2] = max(city[1], city[2]);
		for (int i = 3; i <= N; i++){
			dp[i] = max((dp[i - 2] + city[i]), dp[i - 1]); // 점화식 Ai = max ( Ai-2 + N, Ai-1 )
		}
		cout << "#" << tc << " " << dp[N] << endl;		
	}
}
