from collections import deque

tickets = [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]

def solution(tickets):
    answer = []
    visited = []
    start_index = 0
        
    for i in tickets:
        if i[0] == 'ICN':
            start_index = i
    
    
    queue = deque([start_index])
    print(queue)
    answer.append(start_index[0])
    
 
    while queue:
        ticket = queue.popleft()
        answer.append(ticket[1])
     # print('popleft ticket', ticket)
        for i in tickets:
            # print('i', i[0], 'ticket', ticket[1])
            if i not in visited and ticket[1]==i[0]:
                queue.append(i)
                # visited.append(i)
                
    print('visited', visited)
        
    return answer

solution(tickets)
