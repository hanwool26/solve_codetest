#include <iostream>
#include <vector>
#include <cstdio>   // freopen
#include <unordered_set>
#include <ctime>

using namespace std;

void DFS(string &temp, string arr, vector<bool> &select, int cnt, int num, unordered_set<string> &set){
	if(cnt == num){
		if( arr > temp){
			set.insert(temp);
		}
		return;
	}
	for(int i=0; i<arr.length(); i++){
		if(select[i] == true) continue;
		select[i] = true;
		temp.push_back(arr[i]);
		DFS(temp, arr, select, cnt+1, num, set);
		temp.pop_back();
		select[i] = false;
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	clock_t start, end;
    string temp;
    string arr;    

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	start = clock();
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int count = 0;
        unordered_set<string> set;
        cin >> arr;
        vector<bool> select(arr.length(), false);
        DFS(temp, arr, select, 0, arr.length(), set);
        cout << "#" << test_case << " " << set.size() << endl;
	}	
	end = clock();
	cout << "duration : " << (double)(end-start) / CLOCKS_PER_SEC;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
