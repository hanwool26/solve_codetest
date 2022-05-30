#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int N;
typedef struct player {
	int idx;
	int team;
	int point;
	player(int idx, int team, int point) {
		this->idx = idx;
		this->team = team;
		this->point = point;
	}
	bool operator<(const struct player& p)const {
		return this->point < p.point;
	}
}Player;


int main() {
	freopen("전투게임.txt", "r", stdin);
	cin >> N;
	char in_t;
	int in_p;
	vector<Player> Players;
	vector<int> save(N, 0);
	unordered_map<char, int> t_point;
	for (int i = 0; i < N; i++) {
		cin >> in_t >> in_p;
		Players.push_back(Player(i, in_t, in_p));		
	}

	sort(Players.begin(), Players.end());
	int total = 0;
	for (int i = 0; i < Players.size(); i++) {
		Player p = Players[i];
		
		int save_point = total - t_point[p.team];
		save[p.idx] = save_point;
		total += p.point;
		t_point[p.team] += p.point;				
	}
	for (auto& i : save) {
		cout << i << endl;
	}
}
