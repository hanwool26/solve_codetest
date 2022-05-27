#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct player {
	int idx;
	int point;
	int team;
	int total;
	player(int idx, int team, int point) {
		this->idx = idx;
		this->point = point;
		this->team = team;
		this->total = 0;
	}
	bool operator<(struct player & p) {
		return this->point < p.point;
	}
}Player;

bool ascending_idx(Player a, Player b) {
	return a.idx < b.idx;
}

int N;
vector<Player> v;
int team_total[27];
int total;
int main() {
	freopen("전투게임.txt", "r", stdin);
	cin >> N;
	char t;
	int p;
	for (int i = 0; i < N; i++) {
		cin >> t >> p;
		v.push_back(Player(i, (t-'a'), p));
	}
	sort(v.begin(), v.end());

	team_total[v[0].team] = v[0].point;
	total = team_total[v[0].team];
	
	for (int i = 1; i < v.size(); i++) {
		int per_total = 0;
		int minus = 0;
		int idx = i-1;
		while (idx > 0 && (v[i].point == v[idx].point)) {
			if (v[idx].team != v[i].team)
				minus = v[idx].point;
			idx--;
		}
		for (int j = 0; j < 26; j++) {
			if (j == v[i].team) continue;
			per_total += team_total[j];
		}
		v[i].total = per_total - minus;
		team_total[v[i].team] += v[i].point;
	}
	sort(v.begin(), v.end(), ascending_idx);
	for (auto& k : v) {
		cout << k.total << endl;
	}
	return 0;

}
