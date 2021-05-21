# ====================================================================================
# Using DFS Algorithm with Backtracking for finding out solution and meeting time limit
#include <iostream>

using namespace std;

int arr[10][25];
int dp[1024][25];
int answer;
int N, M;

void init_case(){
	for(int i=0; i<10; i++){
		for(int j=0; j<25; j++){
			arr[i][j] = 0;
		}
	}	
	
	for(int i=0; i<1024; i++){
		for(int j=0; j<25; j++){
			dp[i][j] = -1;
		}
	}
	answer = 0;
	N=0;
	M=0;
}
bool isempty(int x, int y){
	if(x+1 == N || y+1 == M) return false;
	if(arr[x][y]==0 && arr[x+1][y]==0 && arr[x][y+1]==0 && arr[x+1][y+1] ==0){
		return true;
	}else{
		return false;
	}
}

void print_arr(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-------------" << endl;
}

void solution(int x, int y, int cnt)
{	
	
	if(x > N-1){
		x = 0;
		y = y+1;
	}
	if(y == M-1) {
		if(answer < cnt) {
			answer = cnt;		
		}
		return;
	}
	// Need to back traking technique in order to meet time limit. 
	if( x==0 ){
		int b=0;
		for(int i=0; i<N; i++){
			b |= (arr[i][y] << i);
		}
		if (dp[b][y] >= cnt) return;
		else dp[b][y] = cnt;
	}	
	if(isempty(x,y)){
		arr[x][y] = arr[x+1][y] = arr[x][y+1] = arr[x+1][y+1] = 1;
		solution(x+2, y, cnt+1);
		arr[x][y] = arr[x+1][y] = arr[x][y+1] = arr[x+1][y+1] = 0;
	}
	solution(x+1, y, cnt);		
}


int main(){
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("chip_production_input.txt", "r", stdin);
	cin >> T;
	
	for(int tc=0; tc<T; tc++){
		int input;		
		init_case();
				
		cin >> N >> M;			
		
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> input;
				arr[i][j] = input;
			}
		}
		solution(0,0,0);		
		cout << "#" << tc+1 << " " << answer << endl;
	}
	return 0;
}
