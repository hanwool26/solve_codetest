// https://m.blog.naver.com/PostView.nhn?blogId=ndb796&logNo=221234427842&proxyReferer=https:%2F%2Fwww.google.com%2F

#include <iostream>
using namespace std;

#define INF 1e9

int a[4][4] = {
  { 0, 5, INF, 8 },
  { 7, 0, 9, INF },
  { 2, INF, 0, 4 },
  { INF, INF, 3, 0 }
};

int main() {
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (a[i][k] + a[k][j] < a[i][k]) {
					a[i][j] = a[i][k] + a[k][j];
				}
			}
		}
	}
	cout << a[1][2] << endl;
	return 0;
}
