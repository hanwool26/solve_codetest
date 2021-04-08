#include <iostream>
#include <vector>

using namespace std;

void sort(int start, int end, vector<int> &numbers){
	if(start >= end) {
		return;
	}

    int pivot = start;
    int i = pivot+1;
    int j = end;
    int temp;
    while(i<=j){
    	while(i<=end && (numbers[i] <= numbers[pivot])){
    		i++;
    	}
    	while(j>start && (numbers[j] >= numbers[pivot])){
    		j--;
    	}    	
    	if(i>j){
    		temp = numbers[j];
    		numbers[j] = numbers[pivot];
    		numbers[pivot] = temp;
    	}else{
    		temp = numbers[j];
    		numbers[j] = numbers[i];
    		numbers[i] = temp;
    	}
    }    
    sort(start, j-1, numbers);
    sort(j+1, end, numbers);    
}

int main(){
	vector<int> numbers={1,3,5,7,4,2,8};
	
	for(auto &i:numbers){
		cout << i << " ";
	}
	cout << endl;
	sort(0, 6, numbers);
	
	for(auto &i:numbers){
		cout << i << " ";
	}	
}
