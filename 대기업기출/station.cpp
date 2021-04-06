#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string calc_time(vector<string> station, string curTime, int x){
	
	unordered_map<string, vector<string>> cur;
	
	string curHour = "";
	string curMin = "";
	string nowHour = curTime.substr(0,2);
	for(auto &i:station){
		cur[i.substr(0,2)].push_back(i.substr(3,2));
	}	
	while(true){
		if(cur.find(nowHour) != cur.end()){
			for(auto &i:cur[nowHour]){
				if( i >= curTime.substr(3,2)){
					curHour = nowHour;
					curMin = i;
					break;
				} else if(nowHour!=curTime.substr(0,2)){
					curHour = nowHour;
					curMin = i;
					break;
				}
			}
		}
		if (curMin.length() > 0) break;
		int now = stoi(nowHour);
		now++;
		nowHour = to_string(now);		
	}
	int int_curmin = stoi(curMin);
	int int_curhour = stoi(curHour);
	
	if(int_curmin+x >=60){
		int_curmin = (int_curmin+x)%60;
		int_curhour = int_curhour+1;
		curHour = to_string(int_curhour);
		curMin = to_string(int_curmin);
	} else {
		int_curmin = (int_curmin+x);
		curHour = to_string(int_curhour);
		curMin = to_string(int_curmin);		
	}
	
	return curHour + ":" + curMin;
}

string solution(string curTime, int x, int y, vector<string> curStation, vector<string> transtation){
	string answer = "";
	string curHour = "";
	string curMin = "";
	string trans = "";
	string nowHour = curTime.substr(0,2);
	
	trans = calc_time(curStation,curTime,x);
	answer = calc_time(transtation, trans, y);
	cout << answer;
}

int main(void){
	string curTime = "12:10";
	int x = 30;
	int y = 60;
	vector<string> curStation = { "12:05", "12:20", "13:40"};
	vector<string> transtation = { "13:20", "13:30"};
	
	solution(curTime, x, y, curStation, transtation);
}
