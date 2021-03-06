#include <iostream>
using namespace std;

int answer;
int N, M, K;	// N : 셀 갯수, M : 격리 시간, K : 미생물 군집

typedef struct MAP{
	int x;
	int y;
	int number;
	int direc;
}MAP;

MAP map[1000];
int visit[100][100];

enum direc{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

void delete_duplict(){
	bool flag = false;
	int temp = 0;
	int sum = 0;
	int index;

	for (int i = 0; i < K; i++){
		temp = 0;
		sum = 0;
		index = -1;
		if (map[i].number == 0)continue;
		for (int j = 0; j < K; j++){
			if (map[i].x == map[j].x && map[i].y == map[j].y){
				sum += map[j].number;
				if (temp < map[j].number){
					index = j;
					temp = map[j].number;
				}				
				map[j].number = 0;
			}
		}
		map[index].number = sum;
	}
}

int solution(){
	int number_K = K;
	int sum = 0;
	for (int time = 0; time < M; time++){		
		for (int i = 0; i < number_K; i++){
			if (map[i].number == 0)continue;

			if (map[i].direc == UP){
				map[i].x -= 1; 
			}
			else if (map[i].direc == DOWN){
				map[i].x += 1;
			}
			else if (map[i].direc == LEFT){
				map[i].y -= 1;
			}
			else if (map[i].direc == RIGHT){
				map[i].y += 1;
			}
			if (map[i].x <= 0 || map[i].x >= N - 1 || map[i].y <= 0 || map[i].y >= N - 1){
				map[i].number /= 2;
				if (map[i].direc == UP) map[i].direc = DOWN;
				else if (map[i].direc == DOWN) map[i].direc = UP;
				else if (map[i].direc == LEFT) map[i].direc = RIGHT;
				else if (map[i].direc == RIGHT) map[i].direc = LEFT;
			}
		}
		delete_duplict();
	}
	for (int i = 0; i < number_K; i++){
		sum += map[i].number;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	//freopen("bug_isolation.txt", "r", stdin);

	cin >> T;
	for (int tc = 0; tc < T; tc++){
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++){
			cin >> map[i].x >> map[i].y >> map[i].number >> map[i].direc;
		}		
		cout << "#" << tc + 1 << " " << solution() << endl;
	}
}
