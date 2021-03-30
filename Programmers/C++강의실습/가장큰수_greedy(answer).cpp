#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k){
	string s = "";
	
	for(int i=0; i< number.length(); i++){
		while (!s.empty() && s.back() < number[i] && k > 0) {
			s.pop_back();
			k--;
		}
		if ( k == 0) {
			s += number.substr(i, number.length() - i);
			break;
		}
		s.push_back(number[i]);
	}
	
	return s.substr(0, s.length()-k);
}
	
int main(void){
	string numbers = "1231234";
	int k=3;
	
	cout << solution(numbers, k);
}
