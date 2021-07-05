#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MIN 0
#define MAX 100000
int N, K;
bool  visit[MAX + 1];

int answer;
int cnt;

typedef struct pos {
	int x;
	int depth;
	pos(int a, int b) {
		x = a;
		depth = b;
	}
}Pos;

void bfs() {
	queue<Pos> q;
	q.push(Pos(N, 0));
	int next;

	while (!q.empty()) {
		int cur = q.front().x;
		int depth = q.front().depth;
		q.pop();

		if (depth > answer) break;

		if (cur == K) {
			answer = depth;
			cnt++;			
		}
		else {
			visit[cur] = true;
		}

		for (int i = 0; i < 3; i++) {
			if (i == 0) next = cur - 1;
			if (i == 1) next = cur + 1;
			if (i == 2) next = cur * 2;
			if (next < MIN || next > MAX || visit[next]) continue;
			q.push(Pos(next, depth + 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("12851.txt", "r", stdin);
	cin >> N >> K;
	answer = int(1e9);
	cnt = 0;
	bfs();
	cout << answer << endl << cnt << endl;
}
