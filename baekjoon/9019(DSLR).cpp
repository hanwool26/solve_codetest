#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

int A, B;

unordered_map<int, char> op = { { 1, 'D' }, { 2, 'S' }, { 3, 'L' }, { 4, 'R' } };

typedef struct Visit{
	int prev;
	int state;
}visit;

visit v[10000];
bool dp[10000];
vector<int> result;

void BFS(int num){
	queue<int> q;
	q.push(num);
	
	while (!q.empty()){
		int base_num = q.front();

		q.pop();
		if (base_num == B){
			//cout << A << " " << B << endl;
			while (base_num != A){
				result.push_back(v[base_num].state);
				base_num = v[base_num].prev;
			}
			break;
		}
		for (int i = 1; i <= 4; i++){
			if (i == 1){
				num = base_num * 2;
				if (num > 9999) num = num % 10000;
			}
			else if (i == 2){
				if (base_num == 0) num = 9999;
				else num = base_num - 1;
			}
			else if (i == 3){
				num = (base_num % 1000) * 10 + base_num / 1000;
			}
			else if (i == 4){
				num = (base_num % 10) * 1000 + base_num / 10;
			}
			if (dp[num] != true){
				dp[num] = true;
				v[num].prev = base_num;
				v[num].state = i;
				q.push(num);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	//freopen("9019.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++){
		cin >> A >> B;
        
		for (int i = 0; i < 10000; i++){
			v[i].prev = -1;
            v[i].state = 0;
			dp[i] = false;
		}
        
		result.clear();
		BFS(A);
		reverse(result.begin(), result.end());
		for (auto &i : result){
			cout << op[i];
		}
		cout << endl;
	}
}
