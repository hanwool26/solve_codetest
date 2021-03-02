### kinds of Fully Search
    1. brute force
        - N중 for문으로 푸는 방법 
    2. 순열
    3. BFS
       -BFS는 O(정점 개수) 이기 때문에 N제한이 1초안에 가능할 경우
       -최소를 구하는 문제
       -간선의 가중치가 1일 때
    4. 비트마스크
    5. 백트래킹

### 아이디어 1
    - 답을 찍는 패턴과 문제를 for문으로 1:1 비교
    - 정답일 경우 count하여 List에 추가 
    - max index를 list comprehension으로 구현
