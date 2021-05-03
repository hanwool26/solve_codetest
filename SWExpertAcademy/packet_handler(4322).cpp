#include <iostream>
 
using namespace std;
 
int cpu_endtime[5];
int packet[1000][2];
int answer;
int N;
int tc;
 
unsigned char dp[1001][11][11][11][11][11];
 
bool solution(int idx, int num_cpu)
{
    if (idx == N) {
        return true;
    }
 
    int wq[5] = { 0, }; 
    int start_time = packet[idx][0];
    int handler_time = packet[idx][1];
 
    for (int i = 0; i < num_cpu; i++) {
        if (cpu_endtime[i] < start_time)
            wq[i] = 0;
        else
            wq[i] = cpu_endtime[i] - start_time;
    }
 
    if (dp[idx][wq[0]][wq[1]][wq[2]][wq[3]][wq[4]] == tc*5 + num_cpu) return false;
    dp[idx][wq[0]][wq[1]][wq[2]][wq[3]][wq[4]] = tc*5 + num_cpu;
 
    for (int i = 0; i < num_cpu; i++) {
        int end_time = cpu_endtime[i];
        if (cpu_endtime[i] - start_time + handler_time > 10) continue;
        if (wq[i] == 0)
            cpu_endtime[i] = start_time + handler_time;
        else
            cpu_endtime[i] = cpu_endtime[i] + handler_time;
        if (solution(idx + 1, num_cpu)) {
            cpu_endtime[i] = end_time;
            return true;
        }
        cpu_endtime[i] = end_time;
    }
    return false;
}
 
int main()
{
    int T;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    freopen("packet_handler_input.txt", "r", stdin);
    cin >> T;
 
    for (tc = 0; tc < T; tc++) {
        answer = -1;
        int time, length;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> time >> length;
            packet[i][0] = time;
            packet[i][1] = length;
        }
        for (int cpu = 1; cpu <= 5; cpu++) {
            if (solution(0, cpu)) {
                answer = cpu;
                break;
            }
        }
        cout << "#" << tc + 1 << " " << answer << endl;
    }
    return 0;
}
