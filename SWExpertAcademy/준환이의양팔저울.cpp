/*
3
3
1 2 4
3
1 2 3
9
1 2 3 5 6 4 7 8 9
*/
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int chu_n;

int memo[10][1 << 10][1 << 10];
bool used[10];

int solution(vector<int> &v, int lev, int leftstate, int rightstate, int left_w, int right_w){
	if (left_w < right_w) return 0;
	if (lev == chu_n) return 1;
	if (memo[lev][leftstate][rightstate] != -1) return memo[lev][leftstate][rightstate];
	int cnt = 0;
	for (int i = 0; i < chu_n; i++){
		if (used[i] == true) continue;
		used[i] = true;
		cnt = cnt + solution(v, lev + 1, leftstate | (1 << i), rightstate, left_w + v[i], right_w);
		cnt = cnt + solution(v, lev + 1, leftstate, rightstate | (1 << i), left_w, right_w + v[i]);
		used[i] = false;
	}
	return memo[lev][leftstate][rightstate] = cnt;	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("준환이의양팔저울.txt", "r", stdin);
	
	int tc, temp;
	cin >> tc;

	for (int i = 0; i < tc; i++){
		cin >> chu_n;
		vector<int> chu;
		memset(memo, -1, sizeof(memo));
		memset(used, false, sizeof(used));
		for (int j = 0; j < chu_n; j++){
			cin >> temp; chu.push_back(temp);
		}
		cout << "#" << i + 1 << " " << solution(chu, 0, 0, 0, 0, 0) << endl;
	}
	return 0;
}
