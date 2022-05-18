#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* Fail Function */
// 문자 매칭이 실패했을 때 얼만큼 건너 뛰어야 하는가를 확인하기 위한 function
vector<int> makeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0; 

	for (int i = 1; i < pattern.size(); i++) {
		while (j > 0 && (pattern[i] != pattern[j])) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void kmp(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();
	vector<int > table = makeTable(pattern);	

	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize-1) {
				cout << i - patternSize + 2 << "th" << endl;
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main() {
	vector<int> table;
	string parent = "ababdababcdagfdababc";
	string pattern = "ababc";

	kmp(parent, pattern);
	return 0;
}
