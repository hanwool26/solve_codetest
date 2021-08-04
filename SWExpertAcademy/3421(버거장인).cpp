#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N, M;

int arr[21];
int pair_arr[21];
int visit[21];
int answer;

vector<int> v;

void DFS(int idx, int use, int cnt){
	if (cnt > N+1) return;
	if (v.size() > 0) answer++;
	
	for (int i = idx; i <= N; i++){
		bool flag = false;
		for (int j = 0; j <= N; j++){
			if (visit[j] == true){
				if (pair_arr[j] & (1 << i)){
					flag = true;
				}
			}
		}
		if (flag) continue;
		v.push_back(i);
		visit[i] = true;
		DFS(i + 1, use | (1 << i), cnt + 1);
		visit[i] = false;
		v.pop_back();

	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("3421.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N >> M;
		answer = 0;
		memset(visit, false, sizeof(visit));
		memset(pair_arr, 0, sizeof(pair_arr));
		v.clear();
		for (int i = 0; i < M; i++){
			int a, b;
			cin >> a >> b;
			pair_arr[a] |= (1 << b);
			pair_arr[b] |= (1 << a);
		}
		DFS(1, 0, 0);
		cout << "#" << tc << " " << answer+1 << endl;
	}
}
