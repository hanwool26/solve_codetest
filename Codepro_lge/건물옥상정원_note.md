### 아이디어1
  - 각 건물의 층을 기준으로 해당 층보다 높은 건물을 만났을 때까지의 합을 구함
  - 해당 층보다 높은 건물을 만났을 경우 loop를 빠져나간 뒤 다음건물로 이동
 
### 결과
  - 시간초과로 인해 몇몇 테스트 케이스는 실패 

### 해답
  - building index 에서 자기자신의 옥상을 볼수 있는 빌딩들만 stack 남겨놓고 그 갯수를 구하는 형식
```python
def solution():
    # user_input = input()
    cnt = 0
    sum = 0
    s = []

    num_len = n # int(user_input)
    # print ("Hello Goorm! Your input is " + user_input)

    for i in range(num_len):
        while any(s) and s[-1] <= building[i]:
            s.pop()
        sum += len(s)
        s.append(building[i])
        print(s)
    print(sum)
		
solution()
```
