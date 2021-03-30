#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution(vector<int> scoville, int k){
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(auto &i:scoville) {
		q.push(i);
	}
	
	while(true){
		int min1 = q.top();
		q.pop();
		if(min1>=k) break;
		else if (q.empty()) {
			answer = -1;
			break;
		}
		int min2 = q.top();
		q.pop();
		q.push(min1+(2*min2));
		answer++;		
	}
	return answer;
}
	
	
