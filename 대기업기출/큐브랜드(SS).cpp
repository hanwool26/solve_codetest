/*
- input.txt
1
5
49 48 47 48 49
36 11 11 11 43
32 11 49 11 30
40 11 11 11 29
40 42 50 29 28

1. 인접큐브간 높이 차가 제일 큰 수 
-> 39 (50 - 11) 
2. 인접큐브가 높이가 같을 때, 가장 큰 면적 ( 면적이 같을 경우, 더 큰 높이 숫자로 출력 ) 
-> ans : 11 8
3. 빗물이 고여 웅덩이가 되었을 때, 가장 큰 면적 ( 면적이 같을 경우, 더 큰 높이 숫자로 출력 ) 
-> ans : 29 10

제약사항 
N <= 64, H <= 255
*/


#include <iostream>

#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
int map[65][65];

void print_map(){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("큐브랜드.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N;
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				cin >> map[i][j];
			}
		}
	}
	return 0;
}
