/* Prim */
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef struct pos {
	int x;
	int y;
}Pos;

typedef struct edge {
	int adj;
	long long fee;
	edge(int a, long long b) {
		adj = a;
		fee = b;
	}
	bool operator<(const edge &b)const {
		return fee > b.fee;
	}
}Edge;

Pos p[1001];
int N;
double E;
bool visit[1001];
long long d[1001];

vector<Edge> v[1001];

void print_pos() {
	for (int i = 1; i <= N; i++) {
		printf("(%d %d)\n", p[i].x, p[i].y);
	}
}

long long answer;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;

	freopen("1251.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		memset(visit, false, sizeof(visit));
		answer = 0;
		for (int i = 0; i < 1000; i++) {
			v[i].clear();
		}
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> p[i].x;
		}
		for (int i = 1; i <= N; i++) {
			cin >> p[i].y;
		}
		cin >> E;
		long long tx, ty, dis;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				tx = pow((p[i].x - p[j].x), 2);
				ty = pow((p[i].y - p[j].y), 2);
				dis = tx + ty;
				v[i].push_back(Edge(j, dis));
				v[j].push_back(Edge(i, dis));
			}
		}
		priority_queue<Edge> pq;
		pq.push(Edge(1, 0));
		while (!pq.empty())
		{
			Edge K = pq.top();
			pq.pop();
			int e = K.adj;
			long long cost = K.fee;
			if (visit[e] == false)
			{
				answer += cost;
				visit[e] = true;
				for (int i = 0; i < v[e].size(); i++){
					if (visit[v[e][i].adj] == false){
						pq.push(Edge(v[e][i].adj, v[e][i].fee));
					}
				}
			}
		}

		cout << "#" << tc << " " << (long long)round(answer*E) << endl;
	}
}
/* Kruscal */
/*
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

typedef struct pos{
	int x;
	int y;
}Pos;

typedef struct edge{
	int v1;
	int v2;
	long long fee;
	edge(int a, int b, long long c){
		v1 = a;
		v2 = b;
		fee = c;
	}
	bool operator<(const edge &b) const {
		return fee < b.fee;
	}
}Edge;

Pos p[1001];
int unf[1001];
int N;
float E;

int Find(int v){
	if (unf[v] == v) return v;
	else return unf[v] = Find(unf[v]);
}

bool Union(int v1, int v2){
	v1 = Find(v1);
	v2 = Find(v2);
	if (v1 != v2){
		unf[v1] = v2;
		return true;
	}
	else{
		return false;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;

	freopen("1251.txt", "r", stdin);
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		vector<Edge> ed;
		long long  answer = 0;
		cin >> N;
		
		for (int i = 1; i <= N; i++){
			cin >> p[i].x;
		}
		for (int i = 1; i <= N; i++){
			cin >> p[i].y;
		}
		cin >> E;
		for (int i = 1; i <= N; i++){
			unf[i] = i;
			for (int j = 1; j <= N; j++){
				if (i < j){
					ed.push_back(Edge(i, j, (long long)((long long)pow(abs(p[i].x - p[j].x), 2) + (long long)pow(abs(p[i].y - p[j].y), 2))));
				}
			}
		}
		sort(ed.begin(), ed.end());
		for (int i = 0; i < ed.size(); i++){
			Edge k = ed[i];
			if (Union(k.v1, k.v2)){
				answer += k.fee;
			}
		}
		cout << "#" << tc << " " << (long long)round(answer*E) << endl;
	}
}
*/
