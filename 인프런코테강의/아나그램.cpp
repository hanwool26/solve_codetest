#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string S, T;

int main() {	
	freopen("아나그램.txt", "r", stdin);
	cin >> S >> T;
	string sub_str;
	int cnt = 0;

	unordered_map<char, int> tm;
	unordered_map<char, int> sm;
	
	// init map(hash table)
	for (int i = 0; i < T.length(); i++) {
		sm[S[i]]++;
		tm[T[i]]++;
	}
	int lt, rt;
	lt = 0;
	rt = T.length() - 1;
	while (rt < S.length()) {
		if (sm == tm) cnt++;
		sm[S[lt]]--;		
		if (sm[S[lt]] == 0) sm.erase(S[lt]);
		sm[S[++rt]]++;
		lt++;
	}
	cout << cnt << endl;
}
