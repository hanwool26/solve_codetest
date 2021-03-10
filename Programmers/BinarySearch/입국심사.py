def binary_search(start, end, target, times):
    count = 0
    if start > end:
        return
    
    mid = int((start+end) // 2)
    for i in range(len(times)):
        count+= mid//times[i]    
    print('mid', mid, 'count', count, 'target', target)
    if count == target:
        for i in times:
            print('moudula', mid%i)
            if mid % i == 0:
                return mid
    count+=1
    if count > target:
        end = mid - 1
    else:
        start = mid + 1        
    return binary_search(start,end,target,times)    

def solution(n, times):
    answer = 0
    data = times.copy()
    
    if n <= len(times):
        answer = max(times)
    else:
        answer = binary_search(0, n*max(data), n, times)
    
    print(answer)
    return answer
