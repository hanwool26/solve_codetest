### 아이디어
  - 올림차순으로 people vector 정렬
  - 가장 큰수부터 weight에 추가하고 가장작은 수를 더해 limit을 넘지않는다면 다음 작은 수를 추가
  - limit이 넘으면 answer ++

### 결과
  - 정확도는 모두 맞았지만, 최적화 단계에서 3/5 개 맞음.

### 풀이
```cpp
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx = 0;
    
    sort(people.begin(), people.end());
    
    while(people.size() > idx){        
        int weight = people.back();
        people.pop_back();
        if(people[idx] + weight <= limit){
            answer++;
            idx++;
        } else answer++;

    }
    return answer;
}
```
