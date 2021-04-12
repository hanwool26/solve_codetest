#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <time.h>

using namespace std;

int adding_balance_weight(vector<int> dp, int max, int min, set<int> remain_set){
	int max_count = 0;
	int count;
	vector<int> temp;	// temporary vector
	int adding_bw;
	
	for(int i=1; i<=500; i++){
		temp.assign(dp.begin(), dp.end());
		temp.push_back(i);
		
		int temp_size = temp.size();
		for(int j=0; j<temp_size; j++){
			int dp_pop = temp[j];
			int plus = i+dp_pop;
			int minus = abs(i-dp_pop);
			
			if(plus <= max && plus >= min) temp.push_back(plus);
			if(minus <= max && minus >= min) temp.push_back(minus);
		}
		
		for(auto &i:temp){
			if(remain_set.find(i)!=remain_set.end()){
				count +=1;				
			}
		}
		if(max_count < count){
			max_count = count;
			adding_bw = i;
			// cout << "max adding bw : " << i << endl;
		}
		temp.clear();	
		count = 0;		
	}
	return adding_bw;		
}

int check_possible(set<int> s, vector<int> v, int min, int max){
	int count = 0;
	vector<int> remain;
	set<int> remain_set;
	for(int i = min; i<=max; i++){
		if(s.find(i) != s.end()) {
			// cout << i << " ";
			continue;
		}else{
			remain.push_back(i);
		}
	}
	
	if(remain.size() == 0) return 0;
	else{		
		for(auto &i:remain){
			remain_set.insert(i);
		}
		/*
		cout << endl << "Remain" << endl;
		for(auto &i:remain){
			cout << i << " ";
		}
		*/
		return adding_balance_weight(v, min, max, remain_set);
		cout << endl;
	}
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
	for(auto &i:dp){
		s.insert(i);
	}	
	return check_possible(s, dp, min, max);	
}

int main(void){
	int answer = 0;
	int min_weight = 1;
	int max_weight = 15;
	clock_t start, finish;
	vector<int> balance_weight = {1,2,4,8};	
	
	start = clock();
	answer = solution(balance_weight, min_weight, max_weight);
	cout << "answer : " << answer << endl;
	finish = clock();
	cout << "duration : " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	return 0;
}
