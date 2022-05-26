#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int N, K;
int main() {
	int temp;
	int total_t = 0; // total time
	int cycle;
	int min_task = 1e9;
	freopen("멀티태스킹.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		total_t += temp;
		v.push_back(temp);
		min_task = min(min_task, temp);
	}

	cin >> K;
	if(K>N)	cycle = K / N; // 정전 타임이 작업 수보다 크다면
	for(int i =0;)


}
