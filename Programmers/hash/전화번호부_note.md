### 아이디어
  - phone_book의 첫 인자를 index로 활용해 vector[index] 배열로 나열함
  - 다음 phone_book의 index로 접근하여 해당 vector에서만 숫자 비교 ( substr(0, string.length() )
  - 일치하는 전화번호가 있다면, answer = false 할당 후, 종료
### 결과
  - 정확성 문제는 모두 맞았지만, 효율성에서 반 틀림. 
### 풀이
  - string으로 정렬 후, 앞뒤만 비교하면 됨. * 어렵게 생각할 문제 아니였음!

```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	
	sort(phone_book.begin(), phone_book.end());
	for(int i = 0; i<phone_book.size()-1; i++){
		if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].length())) {
			answer = false;
			break;
		}
	}
    return answer;	
}
```

