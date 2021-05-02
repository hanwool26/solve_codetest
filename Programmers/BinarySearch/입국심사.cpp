#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long min_time = 1;
    long long max_time = (*max_element(times.begin(), times.end()))*(long long)n;
    long long human;
    
    while(min_time <= max_time){
        human = 0;
        long long avg_time = (min_time+max_time) / 2;
        
        for(auto &t:times){
            human += avg_time/t;
        }       
        if (human >= n) {
            answer = avg_time;
            max_time = avg_time-1;
        }else{
            min_time = avg_time+1;
        }        
    }
    return answer;
}
