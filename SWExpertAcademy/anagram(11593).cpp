#include <iostream>
#include <vector>
#include <cstdio>   // freopen
#include <unordered_map>
#include <unordered_set>
#include <ctime>

using namespace std;

int factorial(int num){
	if(num == 1){
		return 1;
	}
	return num*factorial(num-1);
}

int solution(string arr){
	int answer = 0;
	int string_size = arr.length();
	unordered_map<char, int> map;
	unordered_set<char> check_dup;
	
	for(auto &i:arr){
		map[i]++;
	}
	
	for(int i=0; i<string_size-1; i++){
		int prefix = 0;
		int bottom = 0;
		int up = factorial(string_size-i-1);
		for(int j=i+1; j<string_size; j++){			
			if((arr[i] > arr[j]) && (check_dup.find(arr[j])==check_dup.end())){
				bottom = 1;
				check_dup.insert(arr[j]);
				map[arr[j]]--;
				for(int c='A'; c<='Z'; c++){
					if(map.find(c)!=map.end() && map[c] > 0) bottom *= factorial(map[c]);	
				}
				prefix++;
				map[arr[j]]++;
			}			
		}
		check_dup.clear();
		map[arr[i]]--;
		if(bottom !=0) answer += ((prefix*up)/bottom);
		//cout << "answer : " << answer << " up : " << up << " bottom : " << bottom << endl;
	}
	
	return answer; 
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
	/*
	3
	ABC
	DCBA
	BANANA
	*/
	cin>>T;

	start = clock();
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> arr;
        cout << "#" << test_case << " " << solution(arr) << endl;
	}	
	end = clock();
	cout << "duration : " << (double)(end-start) / CLOCKS_PER_SEC;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
