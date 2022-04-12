// 시간초과 발생.
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[20000+1][20000+1];

void print_map(int n){
    for(int i =1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }    
}

void init_map(int n){
    for(int i =1; i<=n; i++){
        for(int j=1; j<=n; j++){            
            map[i][j] = 1e9;            
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;    
    
    //Floyd Warshall 
    init_map(n);
    
    for (auto &attr:edge){
        map[attr[0]][attr[1]] = map[attr[1]][attr[0]] = 1;  
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) {
                    map[i][j] = 0;
                    continue;
                }              
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    //print_map(n);
    int max = -1;
    int num;
    for(int i=2; i<=n; i++){
        num = map[1][i];
        if(num > max){
            answer = 1;
            max = num;
        }else if (num == max){
            answer++;
        }        
    }    
    return answer;
}
