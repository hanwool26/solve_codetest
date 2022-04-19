#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 1e9;
    int slen = s.length();
    
    for(int slice=1; slice<=slen; slice++){
        string prev;
        int count=0;
        int cnt = 0;
        for(int idx=0; idx<slen/slice; idx++){
            string part=s.substr(idx*slice, slice);       
            if(prev == part){  
                if(cnt < 1){
                    count+=1;                    
                }
                cnt++;
                if(cnt == (10-1)){
                    count+=1;
                }
                    
            }else{
                cnt = 0;
                count += slice;                  
            }
            prev = part;
        }
        count += (slen%slice);
        if(count <= answer) answer = count;
    } 
    return answer;
}
