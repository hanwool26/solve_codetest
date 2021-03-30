#include <iostream>
#include <vector>

using namespace std;

void sort(int start, int end, vector<int> &numbers){
	if(start >= end) {
		return;
	}
    int pivot = start;
    int temp;
    int i, j = 0;
    
    while(true){
        for(i=pivot+1; i<=end; i++){
            if(numbers[i] > numbers[pivot]) break;
        }
        for(j=end; j>start; j--){
            if(numbers[j] < numbers[pivot]) break;        
        }
        temp = numbers[j];
        numbers[j] = numbers[i];
        numbers[i] = temp;
		cout << "i j" << numbers[i] << numbers[j] << endl;  
		if (i>j) break;      
    }
    temp = numbers[i];
    numbers[i] = numbers[pivot];
    numbers[pivot] = temp;
    cout << temp << endl;
    
    
    sort(start, j-1, numbers);
    sort(j+1, end, numbers);    
}

int main(){
	vector<int> numbers={1,3,5,7,4,2,8};
	
	for(auto &i:numbers){
		cout << i << " ";
	}
	cout << endl;
	sort(0, numbers.size()-1, numbers);
	
	for(auto &i:numbers){
		cout << i << " ";
	}
	
}
