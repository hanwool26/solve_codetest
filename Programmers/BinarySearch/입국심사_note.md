### 아이디어
  - 한 심사대마다 n명이 들어갔을 경우의 시간을 입력
  - binary_search로 MID 값을 조정하면서 해당 MID값을 각 심사대의 소요시간으로 나눴을 때의 값을 count함
  - count가 n보다 작으면 start를 mid + 1로 변경, n보다 크면 end를 mid - 1로 조정.
  - count와 n값이 동일할 때의 mid 값을 return
  - count값과 n값이 일치하더라도 해당 mid을 각 시간으로 나눴을 때, 최소 한번은 정수값이 나와야함
### 결과
  - 77.8점 (7 / 9)
