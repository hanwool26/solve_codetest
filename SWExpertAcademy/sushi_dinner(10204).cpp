#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
  int n;
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  freopen("sushi_input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<int> arr;
        cin >> n;
        long long sol = 0;
        for(int i=0; i<n; i++){
            int a,b; cin>> a >> b;
            arr.push_back(a+b);
            sol = sol-b;
        }
        sort(arr.begin(), arr.end());
        for(int j=n-1; j>=0; j=j-2){
            sol = sol+arr[j];
        }
        cout << "#" << test_case << " " << sol << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
