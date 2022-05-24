#include <iostream>
#include <vector>
#include <algorithm>
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
		v.push_back({ x, y });
	}

	for (int i = 0; i < T; i++){		
		int x = v[i].x;
		for (int j = 0; j < T; j++){
			int y = v[j].y;
			cnt = 0;
			for (int k = 0; k < T; k++){
				if ((x >= v[k].x && x - v[k].x <=S) &&
					(y >= v[k].y && y - v[k].y <= S)){
					cnt++;
				}
			}
			max_v = max(cnt, max_v);
		}		
	}
	cout << max_v;
	return 0;
}
