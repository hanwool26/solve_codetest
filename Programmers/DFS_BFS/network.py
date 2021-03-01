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
        # print('node is already visited', node)
        pass
            

def solution(n, computers):
    answer = 0
    global count
    visited = []
    old = []
    for i in range(n):
        dfs(computers[i], visited, answer, computers)
        # print('visited :', visited)
        if is_visited_changed(old, visited):
            #count += 1
            old = visited.copy()

        answer += 1
        
    # print('visitied list :', visited)
    # print('count :', count)
    return count
