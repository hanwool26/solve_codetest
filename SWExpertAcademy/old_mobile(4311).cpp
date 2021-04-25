#include <iostream>
//#include <vector>
#include <string>

using namespace std;

int dp[1000];
int op[5];
int num[10];
int resource[1000]; 
int resource_index;
bool visit[10];
int answer;
int N, O, M, W;

typedef class vector{
	public:
		int arr[10];
		int index;
		vector(){
			index = 0;
			//size = 0;
			for(int i=0; i<10; i++){
				arr[i] = 0;
			}
		}		
		void push_back(int num){
			arr[index++] = num;
		}		
		void pop_back(){
			arr[index--] = 0;
		}		
		int get_size(){
			return index;
		}
}vector;

void init_testcase(){
	for(int i=0; i<1000; i++){
		dp[i] = 0;	
		resource[i]=0;	
	}
	for(int i=1; i<5; i++){
		op[i] = 0;
	}
	for(int i=0; i<9; i++){
		num[i] =0;
		visit[i] = false;
	}	
	resource_index=0;	
	answer=-1;
}

void solution(int cnt, int num, int idx){
	//cout << "soltuion" << endl;
	int temp;
	int cnt_temp;
	if(num < 0 || num > 999 || cnt > M) {
		//cout << "invalid num : " << num << " " << cnt << " " << M << endl;
		return;
	}	
	/*
	if(dp[num]!=1){
		dp[num]=1;
		resource[resource_index++]=num;
		cout << "input : " << num << endl;
	}
	*/
	if(dp[W] == 1) {
		answer=cnt+1;
		//cout << "answer : " << answer << endl;
		return;
	}
	
	for(int i=0; i<resource_index; i++){
		for(int j=0; j<resource_index; j++){
			//cout << resource[i] << " " << resource[j] << " " << resource_index <<  endl;
			//if(cnt+to_string(resource[i]).length()+to_string(resource[j]).length() > M) break;
			if(op[1]==true) { // +
				temp = resource[i]+resource[j];	
				if(temp < 1000 && dp[temp]==0) 
				{
					resource[resource_index++]=temp;
					dp[temp]=1;
				}
				//solution(cnt+1, temp, j);				
			}
			if(op[2]==true) { // -
				temp = resource[j]-resource[i];
				if(temp > 0 && dp[temp]==0) {
					resource[resource_index++]=temp;
					dp[temp]=1;
				}
				//solution(cnt+1, temp, j);
			}
			if(op[3]==true) { // *
				temp = resource[i]*resource[j];
				if(resource[i] == 16 && resource[j]==62) cout << "found" << endl;
				if(temp <1000 && dp[temp]==0) {
					resource[resource_index++]=temp;
					dp[temp]=1;
				}
				//solution(cnt+1, temp, j);
			}
			if(op[4]==true) { // /
				if(resource[i]!=0 && dp[temp]==0){
					temp = resource[j]/resource[i];
				 	resource[resource_index++]=temp;
				 	dp[temp]=1;
				}
				//solution(cnt+1, temp, j);
			}			
		}					
	}	
	//solution(cnt+1, 0, 0);
}

/* 주어진 숫자로 연산자 없이 만들 수 있는 수 */ 
void make_number(vector &temp, bool visit_[], int cnt, int N, int target){
	if(cnt == target){
		int int_temp;
		string str_temp;
		for(int  i=0; i<temp.get_size(); i++){
			str_temp += to_string(temp.arr[i]);			
		}		
		int_temp = stoi(str_temp);
		dp[int_temp] = to_string(int_temp).length();
		
		resource[resource_index++] = int_temp;		
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
		vector v_temp;
		
		init_testcase();
		for(int i=0; i<N; i++){
			cin >> temp;
			num[i]=temp;
			resource[resource_index++]=temp;
			dp[temp]=1;
		}
		for(int i=0; i<O; i++){
			cin >> temp;
			op[temp]=1;
		}
		cin >> W;
		for(int i=2; i<=3; i++) make_number(v_temp, visit, 0, N, i);
		if(dp[W]>0){
			cout << dp[W] << endl;
			answer = dp[W];
		}else{
			//solution(0, 0, 0);				
		}
		cout << "#" << testcase+1 << " " << answer << endl;
	}	
	return 0;
}
