#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>

using namespace std;

int check_possible(set<int> s, int min, int max){
	int count = 0;
	vector<int> remain;
	for(int i = min; i<=max; i++){
		if(s.find(i) != s.end()) {
			cout << i << " ";
			continue;
		}else{
			remain.push_back(i);
		}
	}
	cout << endl << "Remain" << endl;
	for(auto &i:remain){
		cout << i << " ";
	}
	cout << endl;
	return count;	
}

int solution(vector<int> v, int min, int max){
	vector<int> dp; // all posible weights to measure 
	vector<int> remain;
	set<int> s;
	
	for(int i=0; i<v.size(); i++){
		int w_pop = v[i];
		int dp_size = dp.size();
		dp.push_back(w_pop);
		
		for(int j=0; j<dp_size; j++){
			int dp_pop = dp[j];
			int plus = w_pop+dp_pop;
			int minus = abs(w_pop-dp_pop);
			
			if(plus <= max && plus >= min) dp.push_back(plus);
			if(minus <= max && minus >= min) dp.push_back(minus);
		}
	}	
	/*
	sort(dp.begin(), dp.end());
	dp.erase(unique(dp.begin(), dp.end()), dp.end());
	*/
	for(auto &i:dp){
		s.insert(i);
	}	
	return check_possible(s, min, max);
	
}

int main(void){
	int answer = 0;
	int min_weight = 1;
	int max_weight = 10;
	vector<int> balance_weight = {8,4,9};	
	
	answer = solution(balance_weight, min_weight, max_weight);
	cout << endl;
	cout << "answer : " << answer;
	return 0;
}	
