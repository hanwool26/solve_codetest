#include <iostream>
#include <vector>
using namespace std;

int get_square(vector<vector<int>> &board, int start_x, int start_y, 
		int end_x, int end_y, int max_size){	
	// cout << start_x << ", " << start_y << " / " << end_x << ", " << end_y << endl;
	int N = min(end_x-start_x, end_y-start_y);	
	if(N < max_size){
		return max_size;
	}
	for(int i = start_x; i<start_x+N; i++){
		for(int j = start_y; j<start_y+N; j++){
			if(board[i][j] == 0){
				return 0;
			}
		}
	}
	return N;
}

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int size_x = board.size();
	int size_y = board[0].size();

	int dir_x;
	int dir_y;	
	int max_size = 0;
	int compare_temp = 0;
	
	for(int i=0; i<size_x; i++){
		for(int j=0; j<size_y; j++){
			if(board[i][j] == 1){
				dir_x = i;
				dir_y = j;
				
				while(dir_y < size_y && board[i][dir_y]!=0 &&
				dir_x < size_x && board[dir_x][j]!=0){
					dir_x++;		
					dir_y++;			
				}	                
				compare_temp = get_square(board,i,j,dir_x,dir_y, max_size);
				if(max_size < compare_temp){
					max_size = compare_temp;
				}
				//cout << "Square size : " << get_square(board, i,j,dir_x, dir_y) << endl;
			}
		}
	}
    return max_size*max_size;
}
