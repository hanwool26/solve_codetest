#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets)
{
	vector<string> answer;
	unordered_map<string, vector<string>> route;
	sort(tickets.begin(), tickets.end(), greater<vector<string>>());
	
	for(auto &i:tickets){
		route[i[0]].push_back(i[1]);
	}	
	vector<string> s = {"ICN"};
	
	while(!s.empty()){
		string airport = s.back();
		if(route.count(airport) < 1 || // count의 경우 key값이 존재할 경우 1을 반환 없을 경우 0
									   // find의 경우 key값이 존재할 경우 key의 위치 iter 반환, 없을 경우 name.end() 반 
		route[airport].size() ==0){
			answer.push_back(airport);
			s.pop_back();
		}else{
			s.push_back(route[airport].back());
			route[airport].pop_back();
		}
	}
	reverse(answer.begin(), answer.end());
	return answer;
}

int main(){
    vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"},{"SFO", "ATL"}, 
	{"ATL", "ICN"}, {"ATL","SFO"}};
	solution(tickets);
}
	
