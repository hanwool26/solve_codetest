#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> first_ans[3] = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> score_arr;
    int score;   
    
    for(int i=0; i<3; i++){
        score =  0;
        for(int j=0; j<answers.size(); j++){            
            if(first_ans[i][j%first_ans[i].size()] == answers[j]){
                score += 1;
            }            
        }
        score_arr.push_back(score);        
    }
    int max = *max_element(score_arr.begin(), score_arr.end());
    for(int i=0; i<score_arr.size(); i++){
        if (max == score_arr[i]){
            answer.push_back(i+1);
        }        
    }
    sort(answer.begin(), answer.end(), less<int>());
    return answer;
}
