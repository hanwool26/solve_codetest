// #10507
#include <iostream>
#include <queue>
#include <vector>
#include <ctime>

using namespace std;

int solution(vector<int> v, int n, int p){
    int min = v.front();
    int max = v.back();
    queue<pair<int, int>> q;
    int max_day = 0;
    int idx = 0;

    for(int i = min; i<max; i++){
        if(i==v[idx]){
            q.push(make_pair(i, 1));
            idx++;
        }else if(p>0){
            q.push(make_pair(i, 0));
            p--;
        }else if (p==0){
            if(!q.empty()){
                while(q.front().second){
                    q.pop();
                }
                q.pop();
                q.push(make_pair(i, 0));
            }
        } 
        if(max_day < q.size()) max_day = q.size();
    }
    return max_day;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    clock_t start, end;

    start = clock();

	freopen("english_study.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        int p;
        int day;
        vector<int> v;

        cin >> n;
        cin >> p;
        for(int i=0; i<n; i++){
            cin >> day;
            v.push_back(day);            
        }
        cout << "#" << test_case << " " << solution(v, n, p) << endl;
	}
    end = clock();

    cout << "duration : " << (double)(end-start) / CLOCKS_PER_SEC << endl;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
