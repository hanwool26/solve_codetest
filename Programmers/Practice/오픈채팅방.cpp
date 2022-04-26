#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string> parse[100000];

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> id;
    int idx = 0;

    for(auto &str:record){
        istringstream ss(str);
        string s_buffer;
        while(getline(ss, s_buffer, ' ')){
            parse[idx].push_back(s_buffer);
        }
        idx++;
    }

    for(int i=0; i<idx; i++){
        if(parse[i][0] == "Enter"){
            id[parse[i][1]] = parse[i][2];   
        }else if(parse[i][0] == "Change"){
            id[parse[i][1]] = parse[i][2];
        }
    }

    for(int i=0; i<idx; i++){
        string temp;
        if(parse[i][0] == "Enter"){
            temp = id[parse[i][1]]; 
            temp += "님이 들어왔습니다.";
            answer.push_back(temp);
        }else if(parse[i][0] == "Leave"){
            temp = id[parse[i][1]];
            temp += "님이 나갔습니다.";
            answer.push_back(temp);
        }
    }
    return answer;
}
