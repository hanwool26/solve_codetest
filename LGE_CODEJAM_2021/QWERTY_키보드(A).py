N = int(input())

input_key = []
for i in range(N):
    temp = input()
    input_key.append(temp)

from collections import deque

'''
N = 5
input_key = ['QWERTY', 'LOM', 'FFGGFF', 'VGTRDCF', 'MPML']
# input_key = ['MPML']
'''
line = ['QWERTYUIOP', ' ASDFGHJKL', '  ZXCVBNM']

def find_pos(key):
    # print('key', key)
    for i in range(len(line)):
        for j in range(len(line[i])):
            # print(key)
            if key == line[i][j]:
                # print(line[i][j])
                return i,j

def find_key(sentence):
    time = 0
    queue = deque(list(sentence))
    start = queue.popleft() 
    
    x_pos, y_pos = find_pos(start)
    # print(x_pos, y_pos)
    time+=1
    
    while queue:        
        next_x, next_y = find_pos(queue.popleft())   
        if (next_x>x_pos and next_y>y_pos) or (next_x<x_pos and next_y<y_pos):
            k = 2*(abs(x_pos-next_x)) + (0 if 2*(abs(y_pos-next_y)-abs(x_pos-next_x)) < 0 else 2*(abs(y_pos-next_y)-abs(x_pos-next_x)))
            # print('sum', k)
            time+=k
        else:
            time+=2*(abs(x_pos-next_x)) + 2*(abs(y_pos-next_y))         
        time+=1
        # print(f'({x_pos},{y_pos}), ({next_x},{next_y}) time : {time}, {next_x-x_pos}, {next_y-y_pos}')
        x_pos, y_pos = next_x, next_y        
    return time        
        
for i in input_key:
    print(find_key(i))
