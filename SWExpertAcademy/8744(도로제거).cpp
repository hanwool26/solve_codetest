#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("8744.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N >> M;
		for (int i = 1; i <= N; i++){
			arr[i] = N - 1;
		}
		for (int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			arr[a]--;
			arr[b]--;	// 연결된 간선 제거
		}
		int answer = *min_element(arr+1, arr + N); 
		cout << "#" << tc << " " << answer-1 << endl;
	}
}
