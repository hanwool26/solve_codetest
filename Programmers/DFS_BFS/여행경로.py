from collections import deque

# tickets = [["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL","SFO"]]
tickets = [['ICN','B'],['B','ICN'],['ICN','A'],['A','D'],['D','A']]

def solution(tickets):
    answer = []
    visited = []
    next_stop = 0
    priorty_alph = ["Z","Z"]
        
    for i in tickets:
        if i[0] == 'ICN':
            if i[1] < priorty_alph[1]:
                priority_alph = i
            
            start_index = priority_alph
            
    print(start_index)
    priorty_alph = ["Z", "Z"]        
    
    queue = deque([start_index])
    
    # print(len(queue))
    answer.append(start_index[0])
    visited.append(start_index)
    
 
    while queue:
        ticket = queue.popleft()
        answer.append(ticket[1])
        # print('popleft ticket', ticket)
        for i in tickets:
            # print('i', i[0], 'ticket', ticket[1])
            if i not in visited and ticket[1]==i[0]:
                queue.append(i)
                next_stop = i
        if len(queue) > 1:
            # print('max', queue)
            while queue:
                compared = queue.popleft()
                if priorty_alph[1] > compared[1]:
                    priorty_alph = compared
            queue.append(priorty_alph)
            next_stop = priorty_alph
            
        visited.append(next_stop)
                               
    # print('visited', visited)        
    return answer
