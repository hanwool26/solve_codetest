#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;
int X[300000];
int R[300000];
int M[300000];
long long answer;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

//	freopen("9232.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N >> Q;
		int limit = (1 << 30); 
		for (int i = 1; i <= N; i++){
			cin >> R[i];
			limit = min(limit, R[i]);
			M[i] = limit;			
		}
		for (int i = 1; i <= Q; i++){
			cin >> X[i];			
		}		
		int end_point = N;
		for (int i = 1; i <= Q; i++){
			int temp = X[i];
			while (M[end_point] < temp && end_point >= 1) end_point--;
			if (end_point <= 0) continue;
			if (i < Q) end_point--;
		}
		answer = end_point;		
		cout << "#" << tc << " " << answer << endl;
	}
}
