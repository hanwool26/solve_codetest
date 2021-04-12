/*
URL : https://programmers.co.kr/learn/courses/30/lessons/12905
*/

#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int size_x = board.size();
	int size_y = board[0].size();

	int dir_x;
	int dir_y;	
	
	for(int i=0; i<size_x; i++){
		for(int j=0; j<size_y; j++){
			if(board[i][j] == 1){
				cout << i << " " << j << endl;
				dir_x = i;
				dir_y = j;
				
				while(board[dir_x][j]!=0 && dir_x < size_x){
					dir_x++;
				}				
				
				while(board[i][dir_y]!=0 && dir_y < size_y){
					dir_y++;					
				}
				cout << i << ", " << j << " / " << dir_x << ", " << dir_y << endl;
			}
		}
	}
    return answer;
}

int main(void){
	vector<vector<int>> board = {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
	cout << solution(board);
	return 0;
}
