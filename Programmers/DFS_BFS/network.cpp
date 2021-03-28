#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> old;
vector<int> visited;

int count = 0;

bool is_visited_changed(vector<int> old, vector<int> visited)
{
	cout << "is_visited_changed in" << endl;
	if (visited == old){
		return false;
	}else{
		count++;
		return true;
	}
}

void DFS(vector<int> computer, vector<int> visited, int node, vector<vector<int>> computers)
{
	cout << "DFS in" << endl;

	for(int i=0; i<visited.size(); i++){
		cout << "node " << node << "visited " << visited[i] << endl;
		if(node == visited[i]){
			cout << "visited == node" << endl;
			return;
		}
	}
	cout << "node" << node << endl;
	visited.push_back(node);
	for(int i=0; i<computers[node].size(); i++){
		if (i==node) continue;
		if (computers[node][i]) {
			DFS(computers[i], visited, i, computers);
		}
	}	
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
    	DFS(computers[i], visited, i, computers);
    	if (is_visited_changed(old, visited) == true) {
    		cout << "copy" << endl;
    		old = visited;
    		
    	}
    }
    answer = count;
    return answer;
}

int main()
{
	vector<vector<int>> computers = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
	int n = 3;	
	
	cout << solution(n, computers) << endl;
}
