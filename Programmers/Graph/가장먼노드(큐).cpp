#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> graph[20000+1];
bool visit[20000+1];

typedef struct node{
    int v;
    int dis;
    node(int a, int b){
        v = a;
        dis = b;
    }
}Node;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(auto &k:edge){
        graph[k[0]].push_back(k[1]);
        graph[k[1]].push_back(k[0]);
    }
    
    int max = -1;
    queue<Node> q; 
    q.push(Node(1, 0));
    visit[1] = true;
    while(!q.empty()){
        int top = q.front().v;
        int dis = q.front().dis;
        q.pop();
        
        if(dis > max){
            max = dis;
            answer = 1;
        }else if(dis == max){
            answer++;
        }
        
        for(int i=0; i<graph[top].size(); i++){
            int next = graph[top][i];
            if (visit[next] == true) continue;
            q.push(Node(next, dis+1));
            visit[next] = true;
        }
    }    
    return answer;
}
