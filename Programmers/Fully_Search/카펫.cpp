#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i<=yellow; i++){
        int y_width = yellow/i;
        int y_height = i;
        if ((y_width * y_height) != yellow) continue;
        int b_width = (y_width+2) * 2;
        int b_height = y_height*2;
        if ( brown == b_width + b_height){
            answer.push_back(b_width/2);
            answer.push_back(b_height/2+2);
            break;
        }
        
    }
    return answer;
}
