#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int index = 0;    
    int k = 0;
    while(index<progresses.size()){
        k = index;
        int front = progresses[index];
        while(front>=100 && index<progresses.size()){
            front = progresses[++index];           
        }
        k = index - k;
        if(k!=0) {
            //cout << "index : " << index << " k : " << k << endl;
            answer.push_back(k);
        }
        for(int i=index; i<progresses.size(); i++){
            progresses[i]+=speeds[i];
        }
    }        
    return answer;
}
