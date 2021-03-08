def solution(brown, yellow):
    width = 0
    height = 0
    i = 1
    answer = []
    
    while True:
        base_width = int(yellow/(i))
        base_height = int(i)
        
        if base_width < base_height:
            continue
        
        print(base_width, base_height)
        
        j = 1
        while True:
            width = base_width*(2*j)
            height = base_height*(2*j)
    
            brown_sum = width+height+4
            print(brown_sum)
            if brown_sum > brown:
                break
            elif brown_sum == brown:
                index = j
                break
            j+=1
        i+=1
        if brown_sum == brown:
            break
    answer.append(base_width+(2*index))
    answer.append(base_height+(2*index))
    
    return answer
