#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int max;

void DFS(vector<vector<int>> triangle, vector<int> &total, int *size, int sum, int depth, int index)
{
	if(depth > *size-1 || index > *size-1){
		return;
	}

    sum += triangle[depth][index];
    if(depth==*size-1){
        total.push_back(sum);  
        return;
    }
    DFS(triangle,total, size, sum, depth+1, index);
    DFS(triangle, total, size, sum, depth+1, index+1);    
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> total;
    vector<vector<int>> visit;
    int size = triangle.size();
    DFS(triangle,total, &size, 0, 0, 0);
    
    answer = *max_element(total.begin(), total.end());
    //cout << "answer" << answer << endl;
    return answer;
}
