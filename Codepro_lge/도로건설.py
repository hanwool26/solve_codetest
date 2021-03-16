# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
user_input = input()
# print ("Hello Goorm! Your input is " + user_input)

N = int(user_input)
board = []
for i in range(N):
	temp = input()
	board.append(temp)
	
visited = [[0] * N for _ in range(N)]
hap_stack = []
# print(visited)
def dfs(x_dir, y_dir, hap):
    # print(x_dir, y_dir)
    if x_dir == N-1 and y_dir == N-1:
        # print(hap)
        hap_stack.append(hap)
        return
    if y_dir < 0 or x_dir > N-1 or y_dir > N-1:
        return
    
    hap += int(board[x_dir][y_dir])
    visited[x_dir][y_dir] = 1    
    
    if y_dir-1 > 0 and visited[x_dir][y_dir-1] != 1:
        dfs(x_dir, y_dir-1, hap)
    if y_dir+1 < N and visited[x_dir][y_dir+1] != 1:
        dfs(x_dir, y_dir+1, hap)
    if x_dir+1 < N and visited[x_dir+1][y_dir] != 1:
        dfs(x_dir+1, y_dir, hap)
    
dfs(0,0,0)
print(min(hap_stack))
