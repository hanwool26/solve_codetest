count = 0

def is_visited_changed(old, new) -> bool:
    # print(f'old:{old}, new:{new}')
    global count
    if old == new:
        return False
    else:
        count += 1
        return True

def dfs(comp, visited, node, computers):
    global count
    k = -1
    if node not in visited: 
        visited.append(node)
        for neighbour in computers[node]:
            k += 1
            if k == node: # 자기자신은 ixi 이므로 continue
                # print(f'k={k}, node={node}')
                continue
            if neighbour == 1:
                dfs(computers[k], visited, k, computers)
    else:
        pass
            
def solution(n, computers):
    answer = 0
    visited = []
    old = []
    for i in range(n):
        dfs(computers[i], visited, answer, computers)
        # print('visited :', visited)
        if is_visited_changed(old, visited):
            #count += 1
            old = visited.copy() # = 로 대입 시, 같은 id를 참조하게됨. copy 연산자 활용하여 list 복제해야함(swallow copy)
        answer += 1
   
    return count
