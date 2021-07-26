#include <iostream>
using namespace std;
int N, M;

char map[50][50];

void print_map(char (*temp)[50]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout << temp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "========================" << endl;
}

bool check_tile(char(*temp)[50]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (temp[i][j] == '#')  return false;
		}
	}
	return true;
}
void _arr_cpy(char(*dst)[50], char(*src)[50]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			dst[i][j] = src[i][j];
		}
	}
}
bool check_broken(int x, int y,char(*temp)[50]){
	if (temp[x][y] == '#' && temp[x][y + 1] == '#' && temp[x + 1][y] == '#' && temp[x + 1][y + 1] == '#') return true;
	return false;
}
bool answer;
void DFS(int x, int y, char(*temp)[50]){
	//print_map(temp);
	if (answer == true)return;
	if (x > N-1){
		y = y + 1;
		x = 0;
	}
	if (y == M-1){
		if (check_tile(temp)) answer = true;
		return;
	}

	if (check_broken(x, y, temp)){
		temp[x][y] = temp[x][y + 1] = temp[x + 1][y] = temp[x + 1][y + 1] = '.';
		DFS(x + 2, y, temp);
		temp[x][y] = temp[x][y + 1] = temp[x + 1][y] = temp[x + 1][y + 1] = '#';
	}	
	DFS(x + 1, y, temp);
}

bool fix_tile(char(*arr)[50]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (arr[i][j] == '#' && arr[i][j + 1] == '#' && arr[i + 1][j] == '#' && arr[i + 1][j + 1] == '#'){
				arr[i][j] = arr[i][j + 1] = arr[i + 1][j] = arr[i + 1][j + 1] = '.';
			}
		}
	}
	//print_map(arr);
	if (check_tile(arr)){
		return true;
	}
	else return false;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("12502.txt", "r", stdin);
	int T; cin >> T;

	for (int tc = 1; tc <= T; tc++){
		cin >> N >> M;
		answer = false;
		for (int i = 0; i < N; i++){
			char temp[50];
			cin >> temp;
			for (int j = 0; j < M; j++){
				map[i][j] = temp[j];
			}
		}
		if (fix_tile(map)){
			answer = true;
		}
		cout << "#" << tc << " " << ((answer==false) ? "NO" : "YES") << endl;
	}
}
