#include <string>
#include <vector>

using namespace std;

int total;
void DFS(vector<int> numbers, int target, int sum, int n) {
	if(n >= numbers.size()){
		if (sum == target) total++;
		return;
	}
	
	DFS(numbers, target, sum + numbers[n], n+1);
	DFS(numbers, target, sum - numbers[n], n+1);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	DFS(numbers, target, numbers[0], 1);
	DFS(numbers, target, -numbers[0], 1);
	
	answer = total;
	
	return answer;
}

int main(void){
	vector<int> numbers = {1,1,1,1,1};
	int target = 3;
	
	printf("answer : %d\n", solution(numbers, target));
}
