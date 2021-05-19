#include <iostream>
using namespace std;

int N;

typedef struct NUTRITION{
	int p;
	int f;
	int c;
}NUTRITION;

NUTRITION food[40];
NUTRITION nut[3];

int answer[3];
bool visit[40];

void DFS(int index, int p, int f, int c, int cnt){
	int count = 0;
	if (visit[index] == true) return;
	for (int i = 0; i<3; i++){
		if (p > nut[i].p || f > nut[i].f || c > nut[i].c) {
			count++;
			continue;
		}
		if (p == nut[i].p && f == nut[i].f && c == nut[i].c){		
			if (answer[i] == 0) answer[i] = cnt;
			if (answer[i] != 0 && answer[i] > cnt){
				answer[i] = cnt;
			}
		}
	}
	if (count == 3) return;

	visit[index] = true;
	for (int i = index; i < N; i++){
		DFS(i + 1, p + food[i].p, f + food[i].f, c + food[i].c, cnt + 1);
	}
	visit[index] = false; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T;
	freopen("nutrition.txt", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++){
		memset(visit, false, sizeof(visit));
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> food[i].p >> food[i].f >> food[i].c;
		}
		for (int i = 0; i < 3; i++){
			cin >> nut[i].p >> nut[i].f >> nut[i].c;
			answer[i] = 0;
		}
		DFS(0, 0, 0, 0, 0);
		for (int i = 0; i < 3; i++){
			cout << "#" << i + 1 << " " << answer[i] << endl;
		}
	}
}
