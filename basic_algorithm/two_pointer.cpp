// https://butter-shower.tistory.com/226
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v{1,2,3,2,5};
    int start =0, end=0;
    int partial_sum = 0;
    int M = 5;
    int count = 0;

    while (end <= v.size()){
        if(partial_sum >= M){
            partial_sum -= v[start++];
        }
        else if (partial_sum < M){
            partial_sum += v[end++];
        }
        if (partial_sum == M){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
