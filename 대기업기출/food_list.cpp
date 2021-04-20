#include <iostream>
#include <vector>
using namespace std;

typedef struct food{
	int food_idx;
	int carbo; 
	int protein;
	int fat;
}Food;

vector<int> food_list[3];

void print(Food food[], Food target[], vector<bool> &select, int food_size){
	int cnt = 0;

	for(int i=0; i<3; i++){
		if(food_list[i].size() > 0){
			cnt++;
		}
	}
	if (cnt==3) return;	
	int c=0;
	int p=0;
	int f=0;
	vector<int> temp;
	for(int i=0; i<food_size; i++){
		if(select[i] == true){
			cout << food[i].food_idx << " ";
			c+=food[i].carbo;
			p+=food[i].protein;
			f+=food[i].fat;
			temp.push_back(food[i].food_idx);						
		}
	}
	cout << endl;
	for(int j=0; j<3; j++){
		if(food_list[j].size() > 0) continue;
		if(target[j].carbo == c && target[j].protein == p && target[j].fat == f){
			cout << "found" << endl;
			food_list[j].assign(temp.begin(), temp.end());
		}
	}
}

void DFS(Food food[], Food target[], vector<bool> &select, int food_size, int cnt, int num, int idx){
	if(cnt == num) {
		print(food, target, select, food_size);
		return;
	}
	for(int i=idx; i<food_size; i++){
		if(select[i] == true) continue;
		select[i] = true;
		DFS(food, target, select, food_size, cnt+1, num, i);
		select[i] = false;
	}
}

int main(void) {
	int N;
	int testcase;
	int input;

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("nutri_input.txt", "r", stdin);
	cin >> N;

	for (testcase = 0; testcase < N; testcase++) {
		int food_num; cin >> food_num;
		Food food[food_num];
		Food target[3];
		vector<bool> select(food_num, false);
		for(int i=0; i<food_num; i++){
			int c,p,f;
			cin >> c; cin >> p; cin >> f;
			food[i] = {i+1, c, p, f};
		}
		
		for(int i=0; i<3; i++){
			int c,p,f;
			cin >> c; cin >>p; cin >> f;
			target[i] = {i+1, c, p, f};
		}
		cout << "Hi" << endl;	
		for(int i=1; i<food_num; i++){
			DFS(food, target, select, food_num, 0, i, 0);	
		}
		
		for(int i=0; i<3; i++){
			cout << "#" << i << " ";
			if (food_list[i].size() == 0) cout << "0" << endl;
			else{
				for(auto &v:food_list[i]){
					cout << v << " ";
				}
			}
			cout << endl;
		}
	}	
	return 0;
}
