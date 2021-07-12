#include<iostream>
#define MAX_NUM 100001

int A[MAX_NUM] = { 0 };
int B[MAX_NUM] = { 0 };
int S[MAX_NUM] = { 0 };

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;
	freopen("9999.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, L;
		int max_total = 0;


		cin >> L;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> A[i] >> B[i];
			S[i + 1] = S[i] + B[i] - A[i];
		}

		int s = 0;
		int e = 0;
		while (e < N)
		{
			while (s <= e && A[s] + L <= B[e])
			{
				int len = A[s] + L - A[e];
				if (len > 0)
					max_total = max(max_total, S[e] - S[s] + len);
				else
					max_total = max(max_total, S[e] - S[s]);
				s++;
			}
			e++;
		}
		max_total = max(max_total, S[N] - S[s]);

		cout << "#" << test_case << " " << max_total << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
