#include <iostream>
#include <string>
using namespace std;
string S, T;
int encode(string str) {
	int sum = 0;

	for (int i = 0; i< str.length(); i++) {
		int k = str[i] - 'a';
		sum += pow((k + 26), 2);
	}
	return sum;
}
int main() {	
	freopen("아나그램.txt", "r", stdin);
	cin >> S >> T;
	int code = encode(T);
	string sub_str;
	int cnt = 0;

	for (int i = 0; i < (S.length()-T.length()) + 1; i++) {
		sub_str = S.substr(i, T.length());
		if (code == encode(sub_str)) cnt++;
	}
	cout << cnt << endl;
}
