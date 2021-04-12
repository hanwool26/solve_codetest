#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;



int solution(vector<int> v, int min, int max){
	unordered_set<int> s[30];
	
	for(auto &i:v){
		s[1].insert(i);
	}
}

int main(void){
	int answer = 0;
	int min_weight = 1;
	int max_weight = 15;
	vector<int> balance_weight = {1,2,4,8};
	
	answer = solution(balance_weight, min_weight, max_weight);
	return 0;
}
