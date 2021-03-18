user_input = int(input())
board = []
visit = [[10000]*user_input for _ in range(user_input)]

visit[0][0] = 0


for i in range(user_input):
    temp = input()
    board.append(temp)

from collections import deque

x_dir = [-1, 1, 0, 0]
y_dir = [0, 0, -1, 1]

x_pos = 0
y_pos = 0
start = [0,0]
queue = deque([start])

while queue:
    x_pos, y_pos = queue.popleft()
    # print('pos', x_pos, y_pos)
    
    for i in range(4):
        x = x_pos+x_dir[i]
        y = y_pos+y_dir[i]
        if x<0 or x>user_input-1 or y<0 or y>user_input-1:
            continue
        if int(board[x][y]) + int(visit[x_pos][y_pos]) < visit[x][y]:
            visit[x][y] = int(board[x][y]) + int(visit[x_pos][y_pos])   
            queue.append([x,y])
    
    '''
    print('current visit')
    for i in range(user_input):
        print(visit[i])
    '''
    
print(visit[user_input-1][user_input-1])
