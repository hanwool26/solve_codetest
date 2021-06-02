#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int F, S, G, U, D;
int cur_level[1000001];
int visit[1000001] = { false, };

void BFS(){
	queue<int> q;
	q.push(S);
	visit[S] = true;  // 방문처리 제대로해야함.. -> 사소한걸로 시간 소요함.

	while (!q.empty()){
		int cur = q.front();
		q.pop();		
	//	cout << cur << endl;
		if (cur == G){
			cout << cur_level[cur] + 1 << endl;
			return;
		}
		int up = cur + U;
		if (up <= F && visit[up] != true){
			visit[up] = true;
			cur_level[up] = cur_level[cur] + 1;
			q.push(up);
		}		
		int down = cur - D;
		if (down > 0 && visit[down] != true){
			visit[down] = true;
			cur_level[down] = cur_level[cur] + 1;
			q.push(down);
		}
	}
	cout << "use the stairs" << endl;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("5014.txt", "r", stdin);
	memset(cur_level, -1, sizeof(cur_level));
	cin >> F >> S >> G >> U >> D;
	BFS();

}
