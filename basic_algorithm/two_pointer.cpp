// https://butter-shower.tistory.com/226
/*
c.f> 슬라이딩 윈도우
투포인터처럼 구간을 훑으면서 지나간다는 공통점이 있으나 슬라이딩 윈도우는 어느 순간에도 구간의 넓이가 동일하다는 차이점이 있습니다.
*/
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
