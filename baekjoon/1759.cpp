#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char alp[25];
bool visit[25];
char save[25];
int N, R;
int number = 0;

void DFS(int cnt) {

	if (cnt == R) {
		//sort(save, save + R);
		for (int i = 0; i < R; i++) {
			cout << save[i];
			
		}
		//number++;
		cout << endl;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (visit[i] == true) continue;
		save[cnt] = alp[i];
		visit[i] = true;
		DFS(cnt + 1);
		visit[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("1759.txt", "r", stdin);
	memset(visit, false, sizeof(visit));
	cin >> R >> N;
	for (int i = 0; i < N; i++) {
		cin >> alp[i];
	}
	DFS(0);
}
