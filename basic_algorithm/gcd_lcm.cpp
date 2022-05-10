// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kmc7468&logNo=221017936040
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int a = 6;
	int b = 24;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
	return 0;
}
