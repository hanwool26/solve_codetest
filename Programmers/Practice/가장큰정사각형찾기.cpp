#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int columm = board.size();
	int row = board[0].size();
	int max_val = 0;
    
    //cout << columm << " / " << row << endl;
    for(int i=0; i<columm; i++){
    	for(int j=0; j<row; j++){
    		if(board[i][j]!=0 && i-1>=0 && j-1>=0){
    		board[i][j] = min(board[i-1][j-1], min(board[i][j-1], board[i-1][j])) + 1;
    	}
    		if(max_val < board[i][j]) max_val = board[i][j];

    	}
    }
    /*
    for(auto &i:board){
    	for(auto &v:i){
    		cout << v << " ";
    	}
    	cout << endl;
    }
    */

    return pow(max_val,2);
}
