#include <iostream>

using namespace std;

string decimal_to_n(int num, int n) {
	char intToChar[16] = { '0','1','2','3','4','5','6','7',
					   '8','9','A','B','C','D','E','F' };
	int remain;
	string str;
	while (num / n > 0) {
		remain = num % n;
		num /= n;
		str = intToChar[remain] + str;
	}
	remain = num % n;
	str = intToChar[remain] + str;
	return str;
}

int n_to_decimal(string num_str, int n) {
	int value = 0;
	int k;
	for (int i = 0; i < num_str.length(); i++) {
		int k = num_str[i] - '0';
		value = value * n + k;		
	}
	return value;
}

int main() {	
	int num = 153;
	int n = 16;
	string str = decimal_to_n(num, n);
	cout << str << endl;

	int value = n_to_decimal(str, n);
	cout << value << endl;

	return 0;
}
