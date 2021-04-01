### 아이디어
  - phone_book의 첫 인자를 index로 활용해 vector[index] 배열로 나열함
  - 다음 phone_book의 index로 접근하여 해당 vector에서만 숫자 비교 ( substr(0, string.length() )
  - 일치하는 전화번호가 있다면, answer = false 할당 후, 종료
### 결과
  - 정확성 문제는 모두 맞았지만, 효율성에서 반 틀림. 

