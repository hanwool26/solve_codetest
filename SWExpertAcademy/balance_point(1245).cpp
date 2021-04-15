// No. 1245
#include<iostream>

using namespace std;

void solution(int N, int x[], int w[]){
	double result, mid, left, right;
	
	for(int idx=0; idx<N-1; idx++){
		left = x[idx];
		right = x[idx+1];		
		
		for(int k=0; k<100; k++){
			mid = (left+right) / 2.0;
			result = 0;
			for(int i=0; i<=idx; i++){
				result += w[i] / ((mid-x[i])*(mid-x[i]));
			}
			for(int j=idx+1; j<N; j++){
				result -= w[j] / ((mid-x[j])*(mid-x[j]));
			}
			
			if (result > 0){
				left = mid;
			}else{
				right = mid;
			}
		}
		cout << fixed;
		cout.precision(10);
		cout << mid << " ";
	}		
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("balance_point_input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	cout << fixed;
	cout.precision(10);
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		int x[N];
		int w[N];
		for(int i=0; i<N; i++) cin >> x[i];
		for(int i=0; i<N; i++) cin >> w[i];
		
		cout << "#" << test_case << " ";
		solution(N,x,w);
		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
