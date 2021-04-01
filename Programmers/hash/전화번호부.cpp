#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    vector<string> hash;
    bool answer = true;    
    int pos;
    for(auto &i : phone_book){    
        for(auto &j:hash){
        //cout << "p : " << i << " ha" << j << endl;
        if(i.length() > j.length()){
            pos = i.find(j);            
        } else {
            pos = j.find(i);
        }
        if(pos != string::npos){
            answer = false;
            break;
        }
        }
  
        hash.push_back(i);
    }
    return answer;
}
