#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char alp[26];
bool visit[26] = { false, };
char save[15];
char aei[5] = { 'a', 'e', 'i', 'o', 'u' };
int N, R;
int number = 0;

void DFS(int idx, int cnt) {
	if (cnt == R) {
		save[cnt] = '\0';
		int moum = 0;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < 5; j++) {
				if (save[i] == aei[j]) {
					moum++;
				}
			}
		}
		if (moum >= 1 && R - moum > 1){
			cout << save << endl;
			return;
		}
		return;
	}
	for (int i = idx; i < N; i++) {
		if (visit[i] == true) continue;
		save[cnt] = alp[i];
		visit[i] = true;
		DFS(i + 1, cnt + 1);
		visit[i] = false;
	}
}

int main() {
	freopen("1759.txt", "r", stdin);
	//memset(visit, false, sizeof(visit));
	cin >> R >> N;
	for (int i = 0; i < N; i++) {
		cin >> alp[i];
	}
	sort(alp, alp + N);
	DFS(0, 0);
}
