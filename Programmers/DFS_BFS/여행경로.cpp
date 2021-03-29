#include <iostream>
#include <string>
#include <vector>
#include <utility>


using namespace std;

#include <string>
#include <vector>

using namespace std;

void dfs(vector<string> node, vector<vector<string>> tickets, vector<vector<string>>& visit, vector<string>& answer){
	vector<string> next_node = {"Z", "Z"};
	cout << "visit " << node[0] << " " << node[1];
	visit.push_back(node);
	answer.push_back(node[1]);

	for(int i=0; i<tickets.size(); i++)
	{
		cout << tickets[i][0] << tickets[i][1] << tickets.size() << endl;
		for(int j=0; j<visit.size(); j++){
			
			if(tickets[i] == visit[j]) return;
		}
		if(next_node[1] == tickets[i][0]){
			if (next_node[0] > tickets[i][0]){
				next_node = tickets[i];
			}
		}
	}
	if (next_node[0] == "Z") return;
	dfs(next_node, tickets, visit, answer);
}
	



vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> priority_A = {"Z", "Z"};
    vector<string> start_pos;
    vector<vector<string>> visit;
    for(int i=0; i<tickets.size(); i++){
    	if(tickets[i][0] == "ICN"){
    		if(tickets[i][1] < "Z"){
    			priority_A[0] = tickets[i][0];
				priority_A[1] = tickets[i][1];
    		}
    		start_pos = priority_A;
    	}
    }
    cout << start_pos[0] << "/" << start_pos[1] << endl;
    answer.push_back(start_pos[0]);
    dfs(start_pos, tickets, visit, answer);
    for(int i=0; i<answer.size(); i++){
    	cout << answer[i] << " ";
    }
    
    return answer;
}

int main(){
	vector<vector<string>> ticket = {{"ICN", "JFK"}, {"JFK", "HND"}, {"HND", "IAD"}};
	solution(ticket);
}
