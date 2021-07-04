#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MIN 0
#define MAX 100000
int N, K;
bool  visit[MAX+1];

int answer;
int cnt;

typedef struct pos{
	int x;
	int depth;
	pos(int a, int b){
		x = a;
		depth = b;
	}
}Pos;

void bfs(){
	queue<Pos> q;
	q.push(Pos(N, 0));


	visit[N] = true;
	while (!q.empty()){
		int cur = q.front().x;
		int depth = q.front().depth;
		q.pop();
		if (cur - 1 >= MIN && cur - 1 <= MAX && visit[cur - 1] != true){
			q.push(pos(cur - 1, depth + 1));
			if (cur-1 == K){
				if (answer >= depth){
					answer = depth+1;
					cnt++;
				}
			}else visit[cur - 1] = true;
		}
		if (cur + 1 >= MIN && cur + 1 <= MAX && visit[cur + 1] != true){
			q.push(pos(cur + 1, depth + 1));
			if (cur + 1 == K){
				if (answer >= depth){
					answer = depth+1;
					cnt++;
				}
			}
			else visit[cur + 1] = true;
		}
		if (cur * 2 >= MIN && cur * 2 <= MAX && visit[cur * 2] != true){
			q.push(pos(cur * 2, depth + 1));
			if (cur*2 == K){
				if (answer >= depth){
					answer = depth+1;
					cnt++;
				}
			}
			else visit[cur *2] = true;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("12851.txt", "r", stdin);
	cin >> N >> K;
	answer = int(1e9);
	cnt = 0;
	bfs();
	cout << answer << endl << cnt << endl;
}
