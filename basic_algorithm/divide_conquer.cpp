// https://kimch3617.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%B6%84%ED%95%A0%EC%A0%95%EB%B3%B5%EB%B2%95-Divide-and-Conquer
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int BinarySearch(int target){
    int low = 0;
    int high = v.size();
    int middle;

    while(low <= high){
        middle = (low + high) / 2;
        if (target == v[middle]){
            return middle;
        }else if (target > v[middle]){
            low = middle + 1;
        }else {
            high = middle - 1;
        }
    }
    return -1;
}

int main(){
    for(int i = 0; i< 10; i++){
        v.push_back(i);
    }
    cout << BinarySearch(4) << endl;
    return 0;
}
