#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int dp[250][5]; // 0: score 1: start_x, 2: start_y, 3: end_x, 4: end_y
vector<vector<int>> dp;
int dp_idx;




void init_case(){
	for(int i=0; i<dp.size(); i++){
		dp[i].clear();
	}
	dp.clear();
	dp_idx = 0;
}

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

bool cmp(vector<int> a, vector<int> b){
	if(a<b) return true;
	else return false;
}

int solution(int (*wapper)[25], int X, int Y){
	int cnt = 0;
	
	for(int i=0; i<X; i++){
		for(int j=0; j<Y; j++){
			if(wapper[i][j]>=0){
				if(i-1>=0 && j-1>=0) {
					if (wapper[i-1][j]>=0 && wapper[i][j-1]>=0 && wapper[i-1][j-1]>=0){
						int sum = 0;
						
						vector<int> temp;
						sum += (++wapper[i-1][j]);
						sum += (++wapper[i][j-1]);
						sum += (++wapper[i-1][j-1]);
						sum += (++wapper[i][j]);			
					}
				}
			}
		}
	}
	for(int i=0; i<X; i++){
		for(int j=0; j<Y; j++){
			if(wapper[i][j]>=0){
				if(i-1>=0 && j-1>=0) {
					if (wapper[i-1][j]>=0 && wapper[i][j-1]>=0 && wapper[i-1][j-1]>=0){
						int sum = 0;						
						vector<int> temp;
						
						dp.push_back(temp);	
						sum += (wapper[i-1][j]);
						sum += (wapper[i][j-1]);
						sum += (wapper[i-1][j-1]);
						sum += (wapper[i][j]);					
						// input sum with pos
						dp[dp_idx].push_back(sum);
						dp[dp_idx].push_back(i-1);
						dp[dp_idx].push_back(j-1);
						dp[dp_idx].push_back(i);
						dp[dp_idx].push_back(j);
						dp_idx++;				
					}
				}
			}
		}
	}
	
	int N = dp_idx;
	
	sort(dp.begin(), dp.end(), cmp);
	
	/*
	for(int i=0; i<dp.size(); i++){
		cout << dp[i][0] << endl << "(" << dp[i][1] << "," << dp[i][2] << " / " << dp[i][3] << "," << dp[i][4] << ")" << endl;
	}
	*/
	
	int start_x, start_y, end_x, end_y;
	print_wapper(wapper, X, Y);
	for(auto &i:dp){
		start_x = i[1];
		start_y = i[2];
		end_x = i[3];
		end_y = i[4];
		
		if(wapper[start_x][start_y]!=-1 && wapper[start_x+1][start_y]!=-1 && wapper[start_x][start_y+1]!=-1 && wapper[end_x][end_y]!=-1){
			cnt++;
			wapper[start_x][start_y] = wapper[start_x+1][start_y] = wapper[start_x][start_y+1] = wapper[end_x][end_y]=-1;
		}
	}
	print_wapper(wapper, X, Y);

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
		init_case();
		
		for(int i=0; i<X; i++){
			for(int j=0; j<Y; j++){
				cin >> input;
				if (input == 1) input = -1;
				wapper[i][j] = input;
			}
		}
		//print_wapper(wapper, X, Y);
		answer = solution(wapper, X, Y);		
		//print_wapper(wapper, X, Y);
		cout << "#" << tc+1 << " " << answer << endl;
		
	}
		
	return 0;
}
