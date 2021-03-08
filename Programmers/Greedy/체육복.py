def solution(n, lost, reserve):
    answer = 0
    cnt = 0
    len_lost = len(lost)
    temp = lost.copy()
    for i in temp:
        print('step', i)
        if i in reserve:
            print('step2', i)
            cnt+=1
            reserve.remove(i)
            lost.remove(i)
            
            
            print('step3', lost, reserve)
            
    print(cnt, lost, reserve)
    
    for i in lost:
        for j in reserve:
            if j==i+1 or j==i-1:
                cnt+=1
                reserve.remove(j)
                break
                 
    print(cnt)
    answer = n - len_lost + cnt
    return answer
