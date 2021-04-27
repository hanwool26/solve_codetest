#include <iostream>
//#include <vector>
//#include <string>

using namespace std;

int dp[1000];
int origin[1000];
bool op[5];
bool num[10];
bool visit[10];
int answer;
int N, O, M, W;

void init_testcase(){
	for(int i=0; i<1000; i++){
		dp[i] = origin[i] = 0;
	}
	for(int i=1; i<5; i++){
		op[i] = false;
	}
	for(int i=0; i<10; i++){
		num[i] =false;
		visit[i] = false;
	}	
	answer= 21;
}

void solution(int l, int cnt, bool flag){
	if (cnt+flag > M || cnt+flag > answer) return;
	if (l == W) {	
		answer = cnt + flag;
		return;
	}	
	for(int i=0; i<1000; i++){		
		if(!dp[i] || !origin[i]) continue;		
		//cout << i << endl;
		for(int j=1; j<5; j++) {
			if(!op[j])continue;
			if(i==0 && j==4) continue;
			
			int temp;
			if(j==1) temp = l+i;
			else if(j==2) temp = l-i;
			else if(j==3) temp = l*i;
			else if(j==4) temp = l/i;
			

			if(temp < 0 || temp > 999) continue;
			if(dp[temp] == 0 || dp[temp] > cnt+dp[i]+1) {
				
				dp[temp] = cnt + dp[i] + 1;
				solution(temp, dp[temp], 1);
			}
		}
	}	
}
/* 주어진 숫자로 연산자 없이 만들 수 있는 수 */ 
/*
void make_number(vector &temp, bool visit_[], int cnt, int N, int target){
	if(cnt == target){
		int int_temp;
		string str_temp;
		for(int  i=0; i<temp.get_size(); i++){
			str_temp += to_string(temp.arr[i]);			
		}		
		int_temp = stoi(str_temp);
		dp[int_temp] = to_string(int_temp).length();	
		origin[int_temp] = 1;		
		return;
	}
	for(int i=0; i<N; i++){
		if(visit_[i] == true) continue;
		visit_[i] = true;
		temp.push_back(num[i]);
		make_number(temp, visit_, cnt+1, N, target);
		temp.pop_back();
		visit_[i] = false;
	}	
}*/

void make_origin(int dial, int cnt) {
	if (cnt==0){
		if(num[0]) {
			origin[0] = dp[0] = 1;
		}
		for(int i=1; i<10; i++){
			if (num[i]) make_origin(i, 1);
		}
		return;
	}
	if(!dp[dial]) origin[dial]=dp[dial]=cnt;
	else if (dp[dial] > cnt) origin[dial]=dp[dial]=cnt;
	
	if(dial > 99) return;
	for(int i=0; i<10; i++){
		if(num[i]) make_origin(dial*10+i, cnt+1);
	}
}	

int main(){	
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	int T;	
	int temp;
	freopen("old_mobile_input.txt", "r", stdin);
	
	cin >> T;
	
	for(int testcase=0; testcase < T; testcase++){		
		cin >> N >> O >> M;
		init_testcase();
		for(int i=0; i<N; i++){
			cin >> temp;
			num[temp]=true;
		}
		for(int i=0; i<O; i++){
			cin >> temp;
			op[temp]=true;
		}
		cin >> W;
		make_origin(0,0);
		if(dp[W]>0){
			answer = dp[W];
		}else{
			for(int i=0; i<1000; i++){
				if(dp[i] && origin[i]) {
					solution(i, dp[i], 0);	
				}
			}
		}
		cout << "#" << testcase+1 << " " << (answer==21 ? -1 : answer) << endl;
	}	
	return 0;
}
