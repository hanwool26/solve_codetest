// https://hsho.tistory.com/30

#include <iostream>
#include <vector>
using namespace std;

int parent[100]; // 자기 자신으로 초기화

for(int i=0; i<100; i++){
	parent[i] = i;
}

int Find(int x) {
	if (parent[x] == x) return x;
	else {
		return parent[x] = Find(parent[x]);
	}
}

int Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a != b) {
		parent[a] = b;
	}
}
