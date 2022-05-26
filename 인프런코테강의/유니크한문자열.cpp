#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
char uni;


int main() {
	freopen("유니크한문자열.txt", "r", stdin);
	cin >> N >> uni;
	uni = toupper(uni);
	string temp;
	char upper;

	vector<char> v;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		//unordered_set<char> s;
		bool flag = false;
		for (int i = 0; i < temp.length(); i++) {
			upper = toupper(temp[i]);	
			int j;
			for ( j = 0; j < v.size(); j++) {
				if (v[j] == upper) break;
			}
			if (upper == uni) flag = true;
			if(j==v.size()) v.push_back(upper);
		}	
		if (flag) {
			for (char k : v) cout << k;
			cout << endl;		
		}
		v.clear();		
	}
	return 0;
}
