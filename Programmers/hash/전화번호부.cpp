#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    vector<string> v[10];
    int k;
    
    for(auto &p:phone_book){
    	int index = p[0]-48;
    	for(auto &i:v[index]){
    		k = min(i.length(), p.length());
    		if(i.substr(0, k) == p.substr(0,k)){
    			//cout << "i : " << i << " p : " << p;
    			answer = false;
    			break;
    		}
    	}
    	if (answer == false) break;
    	v[index].push_back(p);
    }
    return answer;	
}
