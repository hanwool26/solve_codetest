def binary_search(start, end, target, times, data):
    count = 0
    # print('start', start, 'end', end)
    
    if start > end:
        return
    
    mid = int((start+end) // 2)
    for i in range(len(data)):
        count+= mid//times[i]
    
    # print('mid', mid, 'count', count, 'target', target)

    if count == target:
        for i in times:
            # print('moudula', mid%i)
            if mid % i == 0:
                return mid
    count+=1

    if count > target:
        end = mid - 1
    else:
        start = mid + 1        
    return binary_search(start,end,target,times,data)    

def solution(n, times):
    answer = 0
    data = times.copy()
    
    for i in range(len(data)):
        data[i] = data[i]*n
    
    answer = binary_search(0, max(data), n, times, data)
    
    #print(answer)
    return answer
