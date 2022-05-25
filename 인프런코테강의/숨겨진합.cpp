#include <iostream>
using namespace std;

int to_int(string str) {
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		int k = str[i] - '0';
		sum = sum * 10 + k;
	}
	return sum;
}

int main() {
	freopen("숨겨진합.txt", "r", stdin);
	string temp;
	cin >> temp;
	int sum = 0;

	for (int i = 0; i < temp.length(); i++) {
		string num;
		if (temp[i] <= '9') {
			int k = i;
			while (temp[k] != '\0' && temp[k] <= '9') {
				num += temp[k++];
			}
			i = k;
		}
		sum += to_int(num);
	}
	cout << sum << endl;
}
