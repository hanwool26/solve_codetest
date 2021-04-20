#include <iostream>
#include <vector>

using namespace std;


vector<int> food_list[3];

void DFS(vector<vector<int>> food, vector<int> nutri_v[], vector<bool>& select, int idx, int cnt, int num) {
	if (cnt == num) {
		int f = 0;
		int p = 0;
		int s = 0;
		for (int i = 0; i < food.size(); i++) {
			if (select[i] == true) {
				f+=food[i][0];
				p+=food[i][1];
				s+=food[i][2];				
			}
		}
		for (int i = 0; i < 3; i++) {
			if (nutri_v[i][0] == f && nutri_v[i][1] == p && nutri_v[i][2] == s) {
				if (food_list[i].size() > 0) continue;
				for (int j = 0; j < food.size(); j++) {						
					if (select[j] == true) {
						//cout << i + 1 << " ";
						food_list[i].push_back((j + 1));
					}					
				}
			}
		}
		return;
	}
	for (int i = idx; i < food.size(); i++) {
		if (select[i] == true) continue;
		select[i] = true;
		DFS(food, nutri_v, select, idx, cnt + 1, num);
		select[i] = false;
	}
}

int main(void) {
	int N;
	int testcase;
	int input;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("sample_input.txt", "r", stdin);
	cin >> N;

	for (testcase = 0; testcase < N; testcase++) {
		int num_food; cin >> num_food;
		vector<vector<int>> food;
		vector<int> nutri_v[3];
		vector<bool> select(num_food, false);
		
		for (int i = 0; i < num_food; i++) {
			vector<int> temp;
			food.push_back(temp);
			for (int j = 0; j < 3; j++) {
				cin >> input;
				food[i].push_back(input);
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> input;
				nutri_v[i].push_back(input);
			}
		}
		for (int i = 1; i < num_food; i++) {
			DFS(food, nutri_v, select, 0, 0, i);
		}

		for (int i = 0; i < 3; i++) {
			cout << "#" << i << " ";
			if (food_list[i].size() == 0) {
				cout << "0";
			}
			for (auto& v : food_list[i]) {
				cout << v << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
