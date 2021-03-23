### 아이디어
  - array에서 min max 값을 구한다. 그 후, 다시 구간을 나누어 min max 값을 구한다. (Binary search)

### 결과
  - 1문제만 맞춤. 
  - Binary Search가 아니라 Dynamic programming 방식으로 최적화 알고리즘 사용해야함. 

```python
user_input = int(input())
array = list(map(int, input().split()))

sum = array[0]
for i in range(1, user_input):
    if array[i-1] < array[i]:
        sum = sum - array[i-1] + array[i]
print(sum)
```
