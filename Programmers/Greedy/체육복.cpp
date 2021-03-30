#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
        int answer = 0;
    vector<int> uniform(n+2, 1);
    
    for(auto& i : reserve){
        uniform[i]++;
    }
    for(auto& i : lost){
        uniform[i]--;
    }
    for(int i = 1; i < uniform.size(); i++){
        if(uniform[i-1] == 0 && uniform[i] > 1){
            uniform[i-1] = 1;
            uniform[i]--;
        }
        if(uniform[i+1] == 0 && uniform[i]>1){
            uniform[i+1] = 1;
            uniform[i]--;           
        }
    }    
    for(int i = 1; i <= n; i++){
        if(uniform[i]>0) answer++;
    }
    return answer;
}
