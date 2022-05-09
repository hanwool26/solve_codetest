#include <iostream>
using namespace std;

int main(){
    char buf[] = "99"; // 153(hex to decimal)
    int sum = 0;
    int n = 16;
    for(int i=0; buf[i]; i++){
        int k = buf[i] - '0';
        sum = sum*n + k;
    }
    cout << sum << endl;
    return 0;
}
