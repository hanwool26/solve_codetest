#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(char *str_a, char *str_b) {
	return strlen(str_a) < strlen(str_b);
}

struct trie {
	trie* node[26];
	bool finish;

	trie() {
		for (int i = 0; i < 26; i++) {
			node[i] = NULL;
		}
		finish = false;
	}
	void insert(char *str) {
		if (*str == NULL) {
			finish = true;
			return;
		}

		int idx = *str - 'a';
		node[idx] = new trie();
		return node[idx]->insert(str + 1);
	}
	bool find(char* str) {
		if (*str == NULL) {
			if (finish == true) return true;
			else return false;
		}
		int idx = *str - 'a';
		if (node[idx] == NULL) return false;
		else node[idx]->find(str + 1);
	}
};



int main() {
	freopen("공통문자열.txt", "r", stdin);
	int T; cin >> T;
	string temp[30];
	string prefix;
	

	for (int tc = 0; tc < T; tc++) {
		cin >> temp[tc];		
	}
	prefix = temp[0];

	for (int i = 1; i < T; i++) {
		for (int j = 0; j < prefix.length(); j++) {
			if (temp[i][j] != prefix[j]) {
				prefix = prefix.substr(0, j);
			}
			//cout << prefix << endl;
		}
	}
	cout << prefix << endl;
}
