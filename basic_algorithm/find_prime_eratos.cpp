// https://donggoolosori.github.io/2020/10/16/eratos/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    vector<int> num;
    int n = 120;

    for(int i=0; i<n; i++){
        num.push_back(i);
    }

    for(int i = 2; i<sqrt(n); i++){
        for(int j = i+i; j<n; j += i){
            if(num[j] == 0) continue;
            if (j % i == 0) num[j] = 0;
        }
    }
    for(auto &i:num)
    {
        if(i!=0) cout << i << endl;
    }
    return 0;
}
