#include <iostream>
#include <vector>

using namespace std;

pair<int, int> solution(string input)
{
	int left = 1;
	int right = 1;
	// Left -> a | a+b
	// Right -> a+b | b
	pair<int, int> node; 
	
	node = make_pair(left, right);
	
	for(int i=0; i<input.length(); i++){
		if(input[i] == 'L'){
			left = left;
			right = left+right;
		}else {
			left = left+right;
			right = right;
		}		
	}
	node = make_pair(left, right);
	return node;	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string input;
	pair<int, int> node;

	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> input;
		node = solution(input);
		cout << "#" << test_case << " " << node.first << " " << node.second << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
