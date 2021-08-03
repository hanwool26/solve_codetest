#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
int N, E;
 
typedef struct node {
    int adj;
    int dis;
    node(int a, int b) {
        adj = a;
        dis = b;
    }
    bool operator<(const node& b) const {
        return dis > b.dis;
    }
}Node;
 
typedef struct edge {
    int v1;
    int v2;
    int dis;
    edge(int a, int b, int c) {
        v1 = a;
        v2 = b;
        dis = c;
    }
    bool operator<(const edge& b) const {
        return dis < b.dis;
    }
}Edge;
 
vector<Node> v[100001];
 
long long answer;
 
void prim_mst() {
    priority_queue<Node> q;
    bool visit[100001];
    memset(visit, false, sizeof(visit));
    q.push(Node(1, 0));
 
    while (!q.empty()) {
        Node temp = q.top();
        q.pop();
        int adj = temp.adj;
        int dis = temp.dis;
        if (visit[adj] != true) {
            visit[adj] = true;
            answer += dis;
            for (int i = 0; i < v[adj].size(); i++) {
                int next = v[adj][i].adj;
                int next_dis = v[adj][i].dis;
                q.push(Node(next, next_dis));
            }
        }
    }
}
 
int unf[100001];
 
int Find(int v) {
    if (unf[v] == v) return v;
    else return unf[v] = Find(unf[v]);
}
 
bool Union(int v1, int v2) {
    int a = Find(v1);
    int b = Find(v2);
    if (a == b) return false;
    else {
        unf[a] = b;
        return true;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    //freopen("3124.txt", "r", stdin);
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> E;
        answer = 0;
        memset(unf, 0, sizeof(unf));
        vector<Edge> ev;
        for (int i = 0; i < E; i++) {
            int v1, v2, e;
            cin >> v1 >> v2 >> e;
            ev.push_back(Edge(v1, v2, e));
            //v[v1].push_back(Node(v2, e));
        }
        //prim_mst();
        for (int i = 1; i <= N; i++) {
            unf[i] = i;
        }
        sort(ev.begin(), ev.end());
        for (int i = 0; i < E; i++) {
            int v1 = ev[i].v1;
            int v2 = ev[i].v2;
            int dis = ev[i].dis;
            if (Union(v1, v2)) {
                answer += dis;
            }
        }
        cout << "#" << tc << " " << answer << endl;
    }
}
