/*
URL : https://programmers.co.kr/learn/courses/30/lessons/12905
*/

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	
	for(int i=0; i<board.size(); i++){
		for(int j=0; j<board[i].size(); j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
    return answer;
}

int main(void){
	vector<vector<int>> board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
	cout << solution(board);
	return 0;
}
