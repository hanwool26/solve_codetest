from collections import deque
visited = []
answer = []

def dfs(node, tickets):
    next_node = ['Z', 'Z']
    visited.append(node)
    answer.append(node[1])
    for i in tickets:
        if i not in visited and node[1] == i[0]:
            if next_node[0] > i[0]:
                next_node = i
    if next_node[0] == 'Z':
        return
    dfs(next_node, tickets)

def solution(tickets):
    priority_alph = ['Z', 'Z']
    for i in tickets:
        if i[0] == 'ICN':
            if i[1] < priority_alph[1]:
                priority_alph = i
                
            start_index = priority_alph
    print(start_index)
    answer.append(start_index[0])
    dfs(start_index, tickets)
    print(answer)
    
    return answer
