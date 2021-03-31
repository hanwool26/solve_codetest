
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int weight;
    
    sort(people.begin(), people.end(), less<int>());
    /*
    for(auto &i:people){
    	cout << i << " ";
    }
    */
    
    while(!people.empty()){
    	weight = 0;
    	weight += people.back();
    	people.pop_back();
    	int i = 0;
    	while(!people.empty()){    		
    		weight += people[i];    		
    		if(weight > limit) break;
    		people.erase(people.begin());
    		i++;
    	}
    	answer++;
    }
    return answer;
}
