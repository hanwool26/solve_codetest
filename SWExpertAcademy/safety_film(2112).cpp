#include <iostream>
using namespace std;

int D, W, K;
int film[13][20];
int answer = 100;
int used[13];

void print_film(int film[13][20]) {
	for (int i = 0; i < D; i++) {
		for (int j = 0; j < W; j++) {
			cout << film[i][j] << " ";
		}
		cout << endl;
	}
}

bool is_pass(int columm) {
	int temp = 0;
	int cal = 0;
	for (int i = 0; i < D; i++) {
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

void insert_chemicals(int film[13][20], int flag, int row) {
	print_film(film);
	cout << "==================================" << endl;
	for (int i = 0; i < W; i++) {
		film[row][i] = flag;
	}
}

void DFS(int film[13][20], int insert_zero, int insert_one, int index) {
	int cnt = 0;
	int(*temp)[20];	// 배열 포인터

	
	for (int i = 0; i < W; i++) {
		if (is_pass(i)) {
			cnt++;
		}
	}
	if (cnt == W) {

		if (answer > insert_zero+insert_one) {
			
			answer = insert_zero+insert_one;
		}
		return;
	}
	if (used[index] == 1) return;
	used[index] = 1;
	for (int i = 0; i < D; i++) {
		temp = film;
		insert_chemicals(temp, 0, i);	
		DFS(temp, insert_zero + 1, insert_one, i);
		temp = film;
		insert_chemicals(temp, 1, i);
		DFS(temp, insert_zero, insert_one+1, i);		
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
		cin >> D >> W >> K;
		for (int i = 0; i < 13; i++) {
			used[i] = 0;
			answer = 100;
		}
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}
		//print_film();
		DFS(film, 0, 0, 0);
		cout << "#" << tc+1 << " " << answer << endl;
	}
}
