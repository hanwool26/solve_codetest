N = int(input())
square = []
i = 0
all_colors = 0
while i < N:
    input_num = input()    
    square.append(input_num)    
    i+=1
        
def is_overpaint(cnt, pos, square, colors):
    up_pos = pos[0]
    down_pos = pos[1]
    
    for i in range(up_pos[0], down_pos[0]+1):
        for j in range(up_pos[1], down_pos[1]+1):
            if cnt != int(square[i][j]):
                if square[i][j] not in colors:
                    # print('overpaint', cnt, square[i][j])
                    colors.append(square[i][j])

def get_contour(upstart, upend, upinc, downstart, downend, downinc, cnt, square):
    for i in range(upstart,upend, upinc):
        for j in range(downstart,downend,downinc):
            if int(square[i][j]) == cnt:
                return [i,j]
    return None

def get_square(left_up, left_down, right_up, right_down):
    x = [min(left_up[0], left_down[0]), min(left_up[1], right_up[1])]
    y = [max(right_up[0], right_down[0]), max(left_down[1], right_down[1])]
    return [x,y]

def find_contour(N, square, colors):
    global all_colors
    left_up, left_down, right_up, right_down = [0,0], [0,0], [0,0], [0,0]
    pos = [0,0]
    
    cnt = 1
    while cnt < 10:
        left_up = get_contour(0,N,1,0,N,1, cnt, square)
        right_up = get_contour(N-1,-1,-1,0,N,1, cnt,square)
        left_down = get_contour(0,N,1,N-1,-1,-1, cnt, square)
        right_down = get_contour(N-1,-1,-1,N-1,-1,-1,cnt, square)
        # print(cnt, left_up, right_up, left_down, right_down)
        if left_up != None:
            all_colors += 1
            pos = get_square(left_up, left_down, right_up, right_down)
            is_overpaint(cnt, pos, square, colors)         
        cnt+=1
        
def print_square(N, square):
    for i in range(N):
        for j in range(N):
            print(square[i][j], end=' ')        
        print('\n')

def solution(N, square):
    colors = []
    # print_square(N, square)
    find_contour(N, square, colors)
    print(all_colors-len(colors))    
    
solution(N, square)
