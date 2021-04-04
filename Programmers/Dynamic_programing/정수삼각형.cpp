#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size()-1;
    
    for(int i=0; i<size; i++){
    	for(int j=0; j<i+1; j++){
    		//cout << triangle[i][j] << endl;
    		if(j!=0){
    			triangle[i+1][j] = max(triangle[i+1][j] + triangle[i][j-1], triangle[i+1][j] + triangle[i][j]);
    		}
    		if(j==0) triangle[i+1][j] = triangle[i][j] + triangle[i+1][j];
    		if(j+1==i+1) triangle[i+1][j+1] = triangle[i][j] + triangle[i+1][j+1];
    	}
    }    			
    answer = *max_element(triangle[size].begin(), triangle[size].end());
    return answer;
}
