### 아이디어1
  - 순열 함수를 사용하여 모든 경우의 수를 만듦
  - original 함수를 solve 함수에 대입한 후 dst와 일치했을 때의 origin 함수를 return 
### 결과
  - 알고리즘은 일치하는 것으로 보이나, N 값이 커질수록 memory out 발생
  - 다른 방법으로 접근 필요.

### 아이디어2
  - solve() 함수에서 value값이 설정되는 부분은 original[index] 값이므로 
    dst value 값에 해당되는 original의 index를 구하여 original[index]로 value 값 할당
  - original 값이 존재하면 original index를 증가시켜 value 값 할당
### 결과
  - 정답
