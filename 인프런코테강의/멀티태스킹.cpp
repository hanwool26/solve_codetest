#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct task {
	long long idx;
	long long time;
	bool finish;
	task(long long idx, long long time, bool finish) {
		this->idx = idx;
		this->time = time;
		this->finish = finish;
	}
	bool operator<(struct task& t) {
		return this->time < t.time;
	}
}Task;

bool ascending_idx(Task a, Task b) {
	return a.idx < b.idx;
}
vector<Task> v;

long long N, K;
int main() {
	long long temp;

	freopen("멀티태스킹.txt", "r", stdin);
	cin >> N;
	v.push_back(Task(0, 0, true));
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		v.push_back(Task(i, temp, false));
	}
	cin >> K;

	sort(v.begin(), v.end());

	long long res = N; // 남아있는 작업. 
	long long per_time;
	long long total_time = 0;
	long long remain_t = 0;
	for (int i = 1; i < v.size(); i++) {
		per_time = (v[i].time - v[i-1].time) * res;		
		if (total_time + per_time > K) {
			remain_t = K - total_time;
			break;
		}
		total_time += per_time;
		res--;
		v[i].finish = true;
	}
	long long answer = -1;
	if (res!=0)
		remain_t %= res;
		sort(v.begin(), v.end(), ascending_idx);

		for (auto& i : v) {
			if (i.finish == true) continue;
			if (remain_t == 0) {
				answer = i.idx;
				break;
			}
			remain_t--;
		}	
	cout << answer << endl;
	return 0;
}
