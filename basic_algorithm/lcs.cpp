// https://www.crocus.co.kr/787

#include <iostream>
#include <string>

using namespace std;

int lcs[10][10];

int main() {
	string str1 = "ACAYKP";
	string str2 = "CAPCAK";

	for (int i = 1; i <= str1.length(); i++) {
		for (int j = 1; j <= str2.length(); j++) {

			if (str1[i-1] == str2[j-1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}
	for (int i = 0; i <= str1.length()+1; i++) {
		for (int j = 0; j <= str2.length()+1; j++) {
			cout << lcs[i][j] << " ";
		}
		cout << endl;		
	}
	cout << lcs[str1.length()][str2.length()] << endl; // 4 : ACAK
	return 0;
}
