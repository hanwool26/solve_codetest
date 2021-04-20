#include <iostream>
#include <cmath>

using namespace std;

int N;
int cnt=0;
int *cols;

bool isPromising(int level) {
	for (int i=1; i<level; i++){
		if(cols[i] == cols[level]) return false;
		else if ((level-i) == abs(cols[level] - cols[i])) return false;
	}
	return true;
}

void queens(int level) {
	if(!isPromising(level)) return;
	else if (level==N) {
		cnt+=1;
		return;
	}
	
	for(int col=1; col<=N; ++col) {
		cols[level+1] = col;
		queens(level+1);
	}
}

int main() {
	cin >> N;
	cols = new int[N+1];
	for(int i=0; i<=N; i++) cols[i] = 0;
	
	queens(0);
	cout << cnt << endl;
}
