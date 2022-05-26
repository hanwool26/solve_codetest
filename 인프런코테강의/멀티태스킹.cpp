#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct time{
	int idx;
	int t;
	time(int idx, int t){
		this->idx = idx;
		this->t = t;
	}
	bool operator<(struct time &b){
		return this->t < b.t;
	}
}Time;

int N, K;
vector<Time> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("멀티태스킹.txt", "r", stdin);
	cin >> N;
	int t;
	for (int i = 1; i <= N; i++){
		cin >> t;
		v.push_back(Time(i, t));
	}
	cin >> K;

	sort(v.begin(), v.end());
	int total_time = 0;
	int idx = -1;
	int per_time = 0;
	for (int i = 0; i < v.size(); i++){
		per_time = v[i].t;
		for (int j = i; j < v.size(); j++){			
			v[j].t = v[j].t - per_time;
			total_time += per_time; 
			if (total_time >= K) {
				idx = j;
				break;
			}
		}
		if (idx != -1) break;
	}
	if (v[idx].t == 0) cout << -1 << endl;
	else cout << v[idx].idx << endl;

	return 0;
}
