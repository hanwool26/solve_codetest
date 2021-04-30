#include <iostream>

using namespace std;

int packet[1000][2];
int answer;

int main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	freopen("packet_handler_input.txt", "r", stdin);
	cin >> T;
	
	for(int tc=0; tc<T; tc++){
		int time, length;
		cin >> N;
		for(int =0; i<N; i++){
			cin >> time >> length;
			pakcet[i][0] = time;
			pakcet[i][1] = length;
		}
		
		cout << "#" << tc+1 << " " << answer;
	}
	
}
