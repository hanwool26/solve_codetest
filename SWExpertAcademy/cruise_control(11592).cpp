#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T;
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	float answer;	
	freopen("cruise_input.txt", "r", stdin);	
	cin >> T;
	for(int tc=0; tc<T; tc++){
		int D, N;
		float horse_T = 0.0;
		
		cin >> D >> N;
		for(int i=0; i<N; i++){
			int K, S;
			float T;
			cin >> K >> S;
			
			T = (D-K)/(float)S;
			if(T > horse_T) horse_T = T;
		}		
		answer = D/horse_T;		
		cout << "#" << tc+1 << " ";
		cout.precision(9);
		cout << answer;
		cout << endl;
	}
	return 0;
}
