#include <iostream>
#include <string.h>

using namespace std;

int D, W, K;

int answer = 100;
int used[13];

void print_film(int(*film)[20]) {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cout << film[i][j] << " ";
		}
		cout << endl;
	}
}

bool is_pass(int(*film)[20], int columm) {
	int temp = 0;
	int cal = 0;
	for (int i = 0; i < D; i++) {
		if (i == D - K + 1 && temp != film[i][columm]) return false;
		if (temp == film[i][columm]) {
			cal++;
			if (cal == K) {
				return true;
			}
		}
		else {
			temp = film[i][columm];
			cal = 1;
		}
	}
	return false;
}


void DFS(int(*film)[20], int index, int insert_num) {
	int cnt = 0;
	int temp[20] = { 0, };
	if (used[index] == 1) return;
	if (insert_num > answer) return;

	// 성능검사
	for (int i = 0; i < W; i++) {
		if (is_pass(film, i)) {
			cnt++;
		}
		else{
			break;
		}
	}
	if (cnt == W) {
		if (answer > insert_num) {
			answer = insert_num;
		}
		return;
	}

	used[index] = 1;
	for (int i = index; i < D; i++) {	// 조합문제일 경우 int i = index로 초기화 한다. 
		memcpy(temp, film[i], sizeof(film[i]));
		for (int j = 0; j < W; j++){
			film[i][j] = 0;
		}
		DFS(film, i+1, insert_num + 1);
		for (int j = 0; j < W; j++){
			film[i][j] = 1;
		}
		DFS(film, i+1, insert_num + 1);
		memcpy(film[i], temp, sizeof(film[i]));
	}
	used[index] = 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	freopen("safety_film.txt", "r", stdin);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		int film[13][20];
		cin >> D >> W >> K;
		memset(used, 0, sizeof(used));
		answer = K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}
		DFS(film, 0, 0);
		cout << "#" << tc + 1 << " " << answer << endl;
	}

}
