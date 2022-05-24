#include <iostream>
#include <vector>
using namespace std;

int W, H, T, S;

#define x first
#define y second

vector<pair<int, int>> v;

int main() {
	freopen("오렌지나무.txt", "r", stdin);

	cin >> W >> H >> T >> S;
	int x, y;
	int cnt = 0;
	int max_v = 0;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}

	for (int i = 0; i < T; i++) {
		cnt = 0;
		for (int j = 0; j < T; j++) {
			if ((v[i].x >= v[j].x && v[i].x - v[j].x <= S) &&
				(v[i].y >= v[j].y && v[i].y - v[j].y <= S)) {
				cnt++;
			}
		}
		max_v = max(max_v, cnt);
	}
	cout << max_v;
		
	return 0;
}
