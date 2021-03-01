### 아이디어 1
  - DFS 알고리즘을 사용하여 방문한노드에 대하여 visited 처리
  - visited가 처리되었으면 return 하여 기존의 네트워크로 인식
  - visited가 되어 있지 않다면 새로운 네트워크로 인식
### 결과
  - is_visited_changed 함수를 제공하여 각 노드마다 dfs 를 거친 후, visited가 업데이트 될 때 카운트 증가
  - 코드는 지저분하고 복잡하지만, 일단 정답
