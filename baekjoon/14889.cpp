#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int N;
int map[21][21];
int answer = int(1e9);

vector<int> V;

int get_score(vector<int> v){
	int sum = 0;
	for (int i = 0; i < N/2 - 1; i++){
		for (int j = i + 1; j < N/2; j++){
			sum = sum + map[v[i]][v[j]] + map[v[j]][v[i]];
		}
	}
	return sum;
}

void DFS(int idx, int cnt, vector<int> v){
	if (v.size() == N / 2){
		vector<int> v2;
		bool flag = false;
		for (int i = 1; i <= N; i++){
			flag = false;
			for (int j =0; j < N / 2; j++){
				if (v[j] == i) flag = true;
			}
			if (flag == false) v2.push_back(i);
		}
		int left = get_score(v);
		int right = get_score(v2);
		if (answer > abs(left - right)){
			answer = abs(left - right);
		}
		return;
	}
	for (int i = idx; i <= N; i++){	
		v.push_back(i);
		DFS(i+1, cnt + 1, v);
		v.pop_back();

	}
}

int main(){
	clock_t start, end;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	start = clock();
	//freopen("14889.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			cin >> map[i][j];
		}
	}
	DFS(1, 0, V);
	cout << answer << endl;
	end = clock();

	//cout << "duration : " << (double)(end - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
