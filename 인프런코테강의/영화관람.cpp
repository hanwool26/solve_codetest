#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	freopen("영화관람.txt", "r", stdin);
	int N; cin >> N;

	stack<int> s; 
	int stu[100001];
	for (int i = 1; i <= N; i++){
		cin >> stu[i];
	}

	for (int i = 1; i <= N; i++){
		int order = 0;
		if (s.empty()){
			s.push(i);
		}
		else{
			while (!s.empty() && stu[s.top()] <= stu[i]){
				s.pop();
			}
			if (s.empty()) order = 0;
			else order = s.top();
			s.push(i);
		}
		cout << order << " ";
	}
	return 0;
}
