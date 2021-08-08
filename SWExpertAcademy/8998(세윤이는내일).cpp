#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct task{
	int t;
	int d;
	task(int a, int b){
		t = a;
		d = b;
	}
	bool operator<(const task &b)const{
		return d > b.d;
	}
}Task;

vector<Task> v;
int N;
int answer;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("10727.txt", "r", stdin);
	int T; cin >> T;
	int a, b;
	for (int tc = 1; tc <= T; tc++){
		v.clear();
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> a >> b;
			v.push_back(Task(a, b));
		}
		sort(v.begin(), v.end());
		int end = v[0].d;
		for (int i = 0; i < v.size(); i++){
			if (end > v[i].d) end = v[i].d;
			end = end - v[i].t;
		}
		cout << "#" << tc << " " << end << endl;
	}
}


