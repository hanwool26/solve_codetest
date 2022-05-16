#include <iostream>
#include <vector>

using namespace std;
#define s_time first
#define p_length second

int N;
int answer;
int cpu_n;
int tc;

vector<pair<int, int>> data;
int cpu_start_time[5];
int dp[1001][11][11][11][11][11];

void init_test(){
	for (int i = 0; i < 5; i++){
		cpu_start_time[i] = 0;
	}
	answer = 0;
}

void dfs(int idx){
	if (idx == N){
		answer = cpu_n;
		return;
	}

	pair<int, int> packet = data[idx];
	int previous_start_time, cpu_end_time;
	int wait_time; int total_time;

	/*-------------------------------------------
	                   가지치기
	--------------------------------------------*/
	int wq[5] = { 0, };
	for (int i = 0; i < cpu_n; i++){
		if (cpu_start_time[i] <= packet.s_time)
			wq[i] = 0;
		else
			wq[i] = cpu_start_time[i] - packet.s_time;		
	}

	if (dp[idx][wq[0]][wq[1]][wq[2]][wq[3]][wq[4]] == tc*5 + cpu_n) return;
	dp[idx][wq[0]][wq[1]][wq[2]][wq[3]][wq[4]] = tc*5 + cpu_n;
	/*-------------------------------------------
	--------------------------------------------*/

	for (int i = 0; i < cpu_n; i++){
		cpu_end_time = previous_start_time = cpu_start_time[i];
		if (cpu_end_time <= packet.s_time){
			cpu_end_time = packet.s_time + packet.p_length;
			wait_time = 0;
		}
		else{
			cpu_end_time = cpu_end_time + packet.p_length;
			wait_time = previous_start_time - packet.s_time;
		}
		total_time = wait_time + packet.p_length;
		if (total_time > 10) continue;
		cpu_start_time[i] = cpu_end_time;
		dfs(idx + 1);
		cpu_start_time[i] = previous_start_time;		
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("packet_handler.txt", "r", stdin);
	int T; cin >> T;

	for (tc = 1; tc <= T; tc++){
		cin >> N;
		int time, length;
		data.clear();
		for (int i = 0; i < N; i++){
			cin >> time >> length;
			data.push_back(make_pair(time, length));
		}
		for (cpu_n = 1; cpu_n <= 5; cpu_n++){
			init_test();
			dfs(0);
			if (answer > 0){
				break;
			}
		}
		cout << "#" << tc << " " << (answer == 0 ? -1 : answer)  << endl;
	}
	return 0;
}
