#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string numbers, int k){
	string answer = "";
	vector<char> temp;
	temp.push_back(numbers[0]);
	int cnt = 0;

	for(int i=1; i<numbers.size(); i++){
		cnt = 0;
		for(int j=temp.size()-1; j>=0; j--){
			cout << "j" << temp[j] << "i" << numbers[i] << endl;
			if(temp[j] < numbers[i]){
				cnt++;
			}
		}
		for(int i=0; i<cnt; i++){
			temp.pop_back();
		}
		temp.push_back(numbers[i]);
		k = k-cnt;
		cout << "k :" << k << " " << cnt << endl;		
		if(k==0) break;
	}
	cout << answer;
	return answer;	
}

int main(void){
	string numbers = "1231234";
	int k=3;
	
	solution(numbers, k);
}
