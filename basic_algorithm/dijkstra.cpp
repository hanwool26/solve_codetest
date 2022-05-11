/*   
7
1 2 4
1 3 2
2 4 4
2 5 5
3 5 4
4 6 1
5 6 2
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
    int v;
    int d;
    edge(int a, int b) {
        this->v = a;
        this->d = b;
    }
     bool operator<(const edge &b) const{
        return this->d > b.d;	// min heap
     }
}Edge;

vector<pair<int, int>> v[10];
vector<int> dist(10, 1e9);
int n;

void dijstra() {
    priority_queue<Edge> pq;
    pq.push(Edge(1, 0));
    dist[1] = 0;

    while (!pq.empty()) {
        int s = pq.top().v;
        int d = pq.top().d;
        pq.pop();
        if (d > dist[s]) continue;	// to reduce the excute time. 
        for (int i = 0; i < v[s].size(); i++) {
            int next = v[s][i].first;
            int next_dis = d + v[s][i].second;
            if (dist[next] > next_dis) {
                dist[next] = next_dis;
                pq.push(Edge(next, next_dis));
            }            
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("다익스트라.txt", "r", stdin);
    cin >> n;

    int a, b, c;
    for (int i = 0; i < n; i++) {
        dist[i] = 1e9;
    }

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c }); // directed graph 이므로 양 정점을 graph에 입력
    }
    dijstra();

    cout << dist[4] << endl;
    return 0;
}
