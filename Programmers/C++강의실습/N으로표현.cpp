#include <iostream>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    unordered_set<int> s[9];
    int base = 0;
    
    for(int i=1; i<8; i++){
        base = 10*base+1;
        s[i].insert(N*base);
    }
    
    for(int i=1; i<9; i++){
    	for(int j=1; j<i; j++){
    		for(auto &op1:s[j]){
    			for(auto &op2:s[i-j]){
    				s[i].insert(op1+op2);
    				s[i].insert(op1*op2);
    				s[i].insert(op1-op2);
    				if (op2!=0) s[i].insert(op1/op2);
    			}
    		}
    	}
    	if(s[i].count(number)) {
			answer = i;
			break;
		}
    }  
    return answer;
}
