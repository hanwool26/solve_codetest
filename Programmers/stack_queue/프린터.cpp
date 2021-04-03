#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> p, int loc) {
	deque<int> dq; 
	vector<int> q;
	
	int order = 0;
	int print = 0;
	int i;
	
	for(auto &i:p){
		dq.push_back(i);
	}
	int find = p[loc];
	
	
	while(!dq.empty()){
		int top = dq.front();

		for(i=1; i<dq.size(); i++){
			if (top < dq[i]) {
				print = 0;
				break;
			}else
				print = 1;
		}		
		if( print==0 ){
			//cout << "+deque : " << "top" << top << " : " << dq[i] << " loc : " << loc << endl;
			dq.push_back(top);
			dq.pop_front();
			if(loc == 0){
				loc = dq.size()-1;
			}else{
				loc--;
			}
		}else{
			//cout << "-deque : " << "top" << top << " : " << dq[i] << " loc : " << loc << endl;
			q.push_back(top);
			if(loc==0){
				//cout << "result order" << endl;
				return order+1;				
			}
			//cout << "top" << dq.front();
			dq.pop_front();
			loc--;
			order++;
			//cout << "order" << order << endl;				
		}
		//cout << "pushed queue" << endl;
		cout << endl;
		
	}	
}
