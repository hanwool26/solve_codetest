### 아이디어
  - len(number)-k 의 range만큼에서 max 값을 구한다
  - max 값의 index를 구한 후 다음 index부터 동일한 방법으로 recursive 함수를 실행한다
  - 최적화를 위해 max = 9 일 경우 break 하며 string slice 방법 대신 index moving 하여 체크한다
### 결과
  - 5문제 런타임 에러, 테스트케이스를 알수가 없어 디버깅 
