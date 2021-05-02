#include <iostream>

using namespace std;

int packet[1000][2];
int end_time;
int answer;
bool is_ok;
int N;

int cpu_endtime[5];

void print_packet()
{
	for (int i = 0; i<N; i++){
		cout << packet[i][0] << " ";
	}
	cout << endl;
	for (int i = 0; i<N; i++){
		cout << packet[i][1] << " ";
	}
	cout << endl;
}

void init_case(){
	for (int i = 0; i<1000; i++){
		packet[i][0] = packet[i][1] = 0;
	}
	answer = -1;
	end_time = 0;

	is_ok = false;
}

void solution(int idx, int num_cpu, int cpu_idx)
{
	//cout << idx << endl;
	if (idx == N) {
		is_ok = true;
		return;
	}
	int wait_time = 0;
	int end_time = cpu_endtime[cpu_idx];

	int start_time = packet[idx][0];
	int handler_time = packet[idx][1];
	if (cpu_endtime[cpu_idx] > start_time){
		wait_time = cpu_endtime[cpu_idx] - start_time;
	}
	start_time = start_time + wait_time;
	//cout << "cpu : " << cpu << " total time per packet : " \
			<< "[" << idx << "] " << wait_time << " " << handler_time << " N : " << N << endl;

	if (wait_time + handler_time > 10) {
		return;
	}
	for (int i = 0; i<num_cpu; i++){
		cpu_endtime[cpu_idx] = start_time + handler_time;
		solution(idx + 1, num_cpu, i);
		cpu_endtime[cpu_idx] = end_time;
	}
}

int main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("packet_handler_input.txt", "r", stdin);
	cin >> T;

	for (int tc = 0; tc<T; tc++){
		init_case();
		int time, length;
		cin >> N;
		for (int i = 0; i<N; i++){
			cin >> time >> length;
			packet[i][0] = time;
			packet[i][1] = length;
		}
		end_time = packet[0][0] + packet[0][1];

		for (int i = 0; i < 5; i++){
			cpu_endtime[i] = 0;
		}

		//print_packet();
		for (int cpu = 1; cpu <= 5; cpu++){
			solution(0, cpu, 0);

			if (is_ok == true) {
				answer = cpu;
				break;
			}
			for (int i = 0; i < 5; i++){
				cpu_endtime[i] = 0;
			}
		}
		cout << "#" << tc + 1 << " " << answer << endl;
	}
	return 0;
}
