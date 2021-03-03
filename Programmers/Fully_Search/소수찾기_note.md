### 아이디어1
  - 파이썬 내장 라이브러리 itertools 사용하여 permutations 함수 사용
  - permutations 사용하면 각 index 값들의 집합들을 list로 감싸서 도출할 수 있음 ex) itertools.permuations(range(1,4), 2)
  - 각 집합들을 다시 int형으로 전환하여 소수 확인
### 결과
  - 일부 시간초과로 2문제 test fail

### 아이디어2
  - is_prime에서 for loop에서 1~n까지의 나눗셈을 확인하는 것이 아니라, n 루트만큼까지 확인해도 똑같은 결과가 나옴 
  - 그래서 n의 값을 math.sqrt(n)으로 변경하고 range를 변경
### 결과
  - 정답
