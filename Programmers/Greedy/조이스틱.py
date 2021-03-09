def solution(name):
    answer = 0
    count = 0
    default = 'A'*len(name)
    list_default = []
    trace_list = []
    standard_char = int((ord('A')+ord('Z'))/ 2)
    
    for index, i in enumerate(name):
        if name == default:
            break
        if ord(i) < standard_char:
            for _ in range(ord('A'), ord(i)):
                count+=1
                trace_list.append('up')                
        elif i == 'A':
            continue
        else:
            for _ in range(ord(i)-1, ord('Z')):
                count+=1
                trace_list.append('down')
        count += 1
        trace_list.append('right')
        
        list_default = list(default)
        list_default[index] = i
        default = ''.join(list_default)
        
    print('trace', trace_list)
    answer = count - 1
    return answer
