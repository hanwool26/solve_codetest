#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int map[9][9];
int hole = 0;
vector<pair<int, int>> v;

void print_map() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool check_sdoku(int idx) {
	unordered_set<int> s;

	int x = v[idx].first;
	int y = v[idx].second;

	for (int i = 0; i < 9; i++) {
		if ((s.find(map[x][i]) != s.end()) && map[x][i] != 0) return false;
		if (map[x][i] != 0) s.insert(map[x][i]);
	}
	s.clear();
	for (int i = 0; i < 9; i++) {
		if ((s.find(map[i][y]) != s.end()) && map[i][y] != 0) return false;
		if (map[i][y] != 0) s.insert(map[i][y]);
	}

	s.clear();
	
	int gx = ((x / 3) * 3);
	int gy = ((y / 3) * 3);
	//cout << gx << " " << gy << endl; 
	for (int i = gx; i < gx + 3; i++){
		for (int j = gy; j < gy + 3; j++){
			if ((s.find(map[i][j]) != s.end()) && map[i][j] != 0) return false;
			if (map[i][j] != 0) s.insert(map[i][j]);
		}
	}
	return true;
}
bool flag = false;
void dfs(int idx) {
	//cout << idx << endl;	
	if (flag) return;
	if (idx == hole) {
		// check array
		flag = true;
		print_map();
		return;
	}

	int cx = v[idx].first;
	int cy = v[idx].second;
	for (int k = 1; k <= 9; k++) {
		map[cx][cy] = k;
		if (!check_sdoku(idx)) {
			map[cx][cy] = 0;	// 0으로 바꿔줘야 부모노드에서 sdoku 체크할 때 중복 숫자로인한 잘못된 return이 없음
			continue;
		}
		dfs(idx + 1);
	}
}

int main() {
	freopen("스도쿠.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) v.push_back({ i, j });
		}
	}
	hole = v.size();
	dfs(0);
}
