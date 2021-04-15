// No. 1245
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

#define INF 1000000000000
using namespace std;

double binarySearch( long double x1,  long double x2, int m1, int m2, int y){
	//cout << x1 << " " << x2 << " " << m1 << " " << m2 << endl;
	if(x1>x2) return 0;
	
	long double d = (x2-x1)/2;
	long double x1_f = m1/pow(d,2);
	long double x2_f = m2/pow((y-d),2);
	cout << fixed;
	cout.precision(11);
	// cout << "d : " << d << " " <<  (x1_f - x2_f) << endl;
	cout.unsetf(ios::fixed);
	
	if(abs(x1_f - x2_f)<=0.1){
		return d;
	} else if ( x1_f - x2_f < 0 && abs(x1_f - x2_f) > 0.1){
		x2 = x1 + d - 0.000000001;
		// cout << "x2 : " << x2 << endl;
		return binarySearch(x1, x2, m1, m2, y);
	} else if ( x1_f - x2_f > 0 && abs(x1_f - x2_f) > 0.1){
		x1 = x1 + d + 0.000000001;
		// cout << "x1 : " << x1 << endl;
		return binarySearch(x1, x2, m1, m2, y);
	}	
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	string input;
	vector<int> v;
	char buffer[256];
	istringstream ss;
	
	freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		int i = 0;
		
		double balance;
		
		cin >> N;
		getchar();
		cout << N << endl;
		cin.getline(buffer, 256);
		istringstream ss(buffer);
		while(getline(ss, input, ' ')){
			v.push_back(stoi(input));
			i++;
		}		
		for(int i=0; i<N-1; i++){
			for(int j=N; j<2*N-1; j++){
				balance = binarySearch((v[i]), (v[i+1]), v[j], v[j+1], v[i+1]-v[i]);
				cout << balance << endl;
			}
		}
		v.clear();

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
