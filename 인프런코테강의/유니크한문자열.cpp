#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N;
char uni;

int main() {
	freopen("유니크한문자열.txt", "r", stdin);
	cin >> N >> uni;
	uni = toupper(uni);
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		transform(a.begin(), a.end(), a.begin(), ::toupper); // 모두 대문자로 
		if (a.find(uni) != string::npos) { // 문자가 존재 
			string res = "";
			for (int i = 0; i < a.size(); i++) {
				if (a.find(a[i]) == i) res += a[i];	// 문자열이 처음 등장. (이 경우 처음 등장하는 문자의 인덱스와 일치함)
			}
			cout << res << endl;
		}
	}
	return 0;
}
