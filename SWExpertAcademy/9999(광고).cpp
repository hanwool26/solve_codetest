#include <iostream>
using namespace std;

int L, N;
int peak[(int)1e8];
int peak_end;

void print_peak(){
	for (int i = 0; i < peak_end; i++){
		cout << peak[i] << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("9999.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> L >>  N;
		for (int i = 0; i < N; i++){
			int s, e;
			cin >> s >> e;
			for (int i = s; i < e; i++){
				peak[i] = 1;
				peak_end = e;
			}
		}

		print_peak();
	}
}
