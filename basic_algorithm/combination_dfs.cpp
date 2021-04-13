#include <iostream>
#include <vector>

using namespace std;

void Print(vector<int> arr, vector<bool> select){
	for(int i=0; i<arr.size(); i++){
		if(select[i] == true){
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}

void DFS(int idx, vector<int> arr, vector<bool> &select, int cnt, int num){
	if(cnt == num){
		Print(arr,select);
		return;
	}
	for(int i=idx; i<arr.size(); i++){
		if(select[i] == true) continue;
		select[i] = true;
		DFS(i, arr, select, cnt+1, num);
		select[i] = false;
	}
}

int main(void){
	vector<int> arr = {1,2,3,4,5};
	vector<bool> select(arr.size(), false);
	vector<int> temp;
	
	DFS(0, arr, select, 0, 3);

	return 0;
}
