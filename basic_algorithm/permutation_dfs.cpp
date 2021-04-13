#include <iostream>
#include <vector>

using namespace std;

void Print(vector<int> temp, vector<int> arr, vector<bool> select){
	for(int i=0; i<temp.size(); i++){
			cout << temp[i] << " ";

	}
	cout << endl;
}

void DFS(vector<int> &temp, vector<int> arr, vector<bool> &select, int cnt, int num){
	if(cnt == num){
		Print(temp, arr,select);
		return;
	}
	for(int i=0; i<arr.size(); i++){
		if(select[i] == true) continue;
		select[i] = true;
		temp.push_back(arr[i]);
		DFS(temp, arr, select, cnt+1, num);
		temp.pop_back();
		select[i] = false;
	}
}

int main(void){
	vector<int> arr = {1,2,3,4,5};
	vector<bool> select(arr.size(), false);
	vector<int> temp;
	
	DFS(temp, arr, select, 0, 5);

	return 0;
}
