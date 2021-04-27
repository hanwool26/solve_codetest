#include <iostream>

using namespace std;

void print_wapper(int (*wapper)[25], int X, int Y)
{
	for(int i=0; i<X; i++){
		for(int j=0; j<Y; j++){
			cout << wapper[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int solution(int (*wapper)[25], int X, int Y){
	int cnt = 2;
	
	for(int i=0; i<X; i++){
		for(int j=0; j<Y; j++){
			if(wapper[i][j]==0){
				if(i-1>=0 && j-1>=0) {
					if (wapper[i-1][j]==0 && wapper[i][j-1]==0 && wapper[i-1][j-1]==0){
						wapper[i-1][j]=wapper[i][j-1]=wapper[i-1][j-1]=wapper[i][j]=cnt;
						cnt++;
						
					}
				}
			}
		}
	}
	
	return cnt;
}

int main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	int answer;
	
	freopen("chip_production_input.txt", "r", stdin);
	cin >> T;
	
	for(int tc=0; tc<T; tc++){
		int X, Y;
		int input;
		cin >> X >> Y;
		int wapper[X][25];
		
		for(int i=0; i<X; i++){
			for(int j=0; j<Y; j++){
				cin >> input;
				wapper[i][j] = input;
			}
		}
		print_wapper(wapper, X, Y);
		answer = solution(wapper, X, Y);		
		print_wapper(wapper, X, Y);
		cout << "#" << tc+1 << " " << answer << endl;
		
	}
		
	return 0;
}
				
				
