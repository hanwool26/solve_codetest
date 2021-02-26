count = 0

# For Debug
# stack = [[] for i in range(10)]

def find_target(k, target, operator, len_numbers, depth, numbers):
    global count    
    # For Debug
    # global stack
    
    # For debug
    # print(f'value : {k}, depth : {depth}, count : {count}, operator : {operator}')
    #stack[depth].append(k)
    
    if depth == len_numbers-1:
        if k == target:
            count = count + 1
        return
    elif depth+1 >= len_numbers:
        return
    
    find_target(k-numbers[depth+1], target, '-', len_numbers, depth+1, numbers)
    find_target(k+numbers[depth+1], target, '+', len_numbers, depth+1, numbers)

def solution(numbers, target):
    answer = 0
    global init_number

    len_numbers = len(numbers)
    print(numbers)
    find_target(0, target, '-', len_numbers, -1, numbers)
    
    '''
    # For Debug
    for i in range(len_numbers+2):
        print(stack[i])
    '''
    return count
