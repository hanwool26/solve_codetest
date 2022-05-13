#include <iostream>
using namespace std;

struct trie {
	bool finish;
	trie* node[26];
	trie()
	{
		finish = false;
		for (int i = 0; i < 26; i++) {
			node[i] = NULL;
		}
	}
	void insert(char* str) {
		if (*str == NULL) {
			finish = true;
			return;
		}

		int index = *str - 'a';
		node[index] = new trie();
		node[index]->insert(str + 1);
	}

	bool find(char* str) {
		if (*str == NULL) {
			if (finish == true)	return true;
			return false;
		}		
		int index = *str - 'a';
		if (node[index] == NULL) 
			return false;
		else 
			return node[index]->find(str + 1);
	}	
};

void print_str(trie* N, char str[], int index) {
	if (N->finish == true) {
		str[index] = '\0';
	cout << str << endl;
}
	for (int i = 0; i < 26; i++) {
		if (N->node[i] != NULL) {
			str[index] = i + 'a';
			print_str(N->node[i], str, index + 1);
		}
	}
}

int main() {
	char str[] = "hello";
	trie* root = new trie();
	root->insert(str);
	bool flag = root->find(str);
	if (flag)
		cout << "found" << endl;
	else
		cout << "no" << endl;
	char temp[10];
	print_str(root, temp, 0);
}
