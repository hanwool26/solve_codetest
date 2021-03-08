def solution(name):
    answer = 0
    i = 0
    count = 0
    center_char = 'N'

    for i in name:
        print('i', i, count)
        if i < center_char:
            for _ in range(ord('A'), ord(i)):
                count+=1
        elif i == 'A':
            continue
        else:
            for _ in range(ord(i)-1, ord('Z')):
                count+=1
        
        count+=1
    
    print('last', name[len(name)-2])
    if name[len(name)-2] == 'A':
        count-=1
           
    print('count', count-1)
    
    answer = count -1
    return answer
