user_input = 3 # int(input())
board = ['041', '253', '620']
visit = [[10000]*user_input for _ in range(user_input)]
visit_tf = [[False]*user_input for _ in range(user_input)]

print(visit_tf)
visit[0][0] = 0

'''
for i in range(user_input):
    temp = input()
    board.append(temp)
'''

from collections import deque

x_dir = [-1, 1, 0, 0]
y_dir = [0, 0, -1, 1]

x_pos = 0
y_pos = 0
start = [0,0]
queue = deque([start])

print(visit[x_pos][y_pos] if visit[x_pos][y_pos]!=10000 else board[x_pos][y_pos])

while queue:
    x_pos, y_pos = queue.pop()
    
    for i in range(4):
        x = x_pos+x_dir[i]
        y = y_pos+y_dir[i]
        if x<0 or x>user_input-1 or y<0 or y>user_input-1:
            continue
        if visit_tf[x][y] != True and visit_tf[x_pos][y_pos] != True:
            if (int(board[x][y]) + int(board[x_pos][y_pos])) < visit[x][y]:
                visit[x][y] = int(board[x][y]) + int(board[x_pos][y_pos])
                visit_tf[x][y] = True
                print(board[x][y], '+', board[x_pos][y_pos])
        if visit_tf[x][y] ==True and visit_tf[x_pos][y_pos] != True:
            if visit[x][y] + int(board[x_pos][y_po])
        queue.append([x,y])
    
    print('current visit')
    for i in range(user_input):
        print(visit[i])

    
print(visit[user_input-1][user_input-1])
