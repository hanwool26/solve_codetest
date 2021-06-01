#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int A, B;
enum oper{
	D =1,
	S,
	L,
	R
};

int dp[10000];


unordered_map<int, char> op = { { 1, 'D' }, { 2, 'S' }, { 3, 'L' }, { 4, 'R' } };
typedef struct node{
	int num;
	vector<char> v;
	node(int a, vector<char> b, int c){
		num = a;
		if (c > 0){
			b.push_back(op[c]);
			v.assign(b.begin(), b.end());
		}		
	}
}Node;

void BFS(int num){

	queue<Node> q;
	vector<char> temp;
	q.push(Node(num, temp, 0));


	while (!q.empty()){
		Node n = q.front();
		q.pop();
		int base_num = n.num;

		if (base_num == B){
			//cout << base_num << endl;
			for (auto &i : n.v){
				cout << i;
			}
			cout << endl;
			break;
		}
		for (int i = 1; i <= 4; i++){
			if (i == 1){
				num = base_num * 2;
				if (num > 10000) num = num % 10000;
			}
			if (i == 2){
				num = base_num - 1;
				if (num == 0) num = 9999;
			}
			if (i == 3){
				num = (base_num % 1000) * 10 + base_num / 1000;
			}
			if (i == 4){
				num = (base_num & 10) * 1000 + base_num / 10;
			}
		//	if (dp[num] == 1) continue;
		//	dp[num] = 1;
			q.push(Node(num, n.v, i));
		}
	}

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("9019.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++){
		for (int i = 0; i < 10000; i++){
			dp[i] = 0;
		}
		cin >> A >> B;
		BFS(A);
	}
}
