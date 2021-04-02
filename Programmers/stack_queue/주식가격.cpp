#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int i = 0;
    int j = 0;
    
    while(i<prices.size())
    {
        for(j=i+1; j<prices.size(); j++){
            if(prices[i] > prices[j]){ 
                break;
            }
        }
        if(j==prices.size()) j--;
        //cout << "i :" << i << "j :" << j << endl;
        answer.push_back(j-i);
        i++;
    }
    return answer;
}
