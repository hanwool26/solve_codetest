import itertools

n = 10
dst = [1,2,4,8,6,3,7,5,10,9]

def solve(org):
    value, cnt, fr = 0,0,0
    dst = []
    
    value = org[fr]
    while cnt < n:
        while value == 0:
            fr = (fr + 1) % n
            value = org[fr]
        dst.append(value)
        cnt+=1
        org[fr] = 0
        fr = (value+fr) % n
        value = org[fr]
    
    # print('dst', dst)
    return dst

def solution(n, dst):
    answer = []
    temp = list(itertools.permutations(dst, n))
    # print(temp)
    
    for i in temp:
        i = list(i)
        # print('org', i)
        answer = i.copy()
        if solve(i) == dst:
            print('same', answer)
    
    # print(answer)

solution(n, dst)
