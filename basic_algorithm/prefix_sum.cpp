// https://gamedevlog.tistory.com/68
#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_sum(const vector<int> &a){
    vector<int> ret(a.size());
    ret[0] = a[0];
    for(int i=1; i< a.size(); i++){
        ret[i] = ret[i-1] + a[i];
    }
    return ret;
}

int range_sum(vector<int> &pSum, int a, int b){
    if(0==a) return pSum[b];
    return pSum[b] - pSum[a-1];
}

int main(){
    vector<int> v{1,2,3,4,5};
    vector<int> sum;

    sum = prefix_sum(v);
    int answer;
    answer = range_sum(sum, 1,3);
    cout << answer << endl;
    return 0;
}
