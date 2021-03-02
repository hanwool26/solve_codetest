count = 0

def is_visited_changed(old, new) -> bool:
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
        for k, neighbour in enumerate(computers[node]):
            if k == node: # 자기자신은 ixi 이므로 continue
                continue
            if neighbour == 1:
                dfs(computers[k], visited, k, computers)
            

def solution(n, computers):
    answer = 0
    global count
    visited = []
    old = []
    for i in range(n):
        dfs(computers[i], visited, i, computers)
        if is_visited_changed(old, visited):
            old = visited.copy()
            
    return count
