numbers = [1,1,1,1,1]
target = 3
count = 0
init_number = 0
stack = [[]*1 for i in range(10)]
def find_target(k, target, operator, len_numbers, depth):
    global count    
    global init_number
    global stack
   
    print(f'value : {k}, depth : {depth}, count : {count}, operator : {operator}')
    
    stack[depth].append(k)
    
    if depth == len_numbers+1:
        if k == target:
            count = count + 1
        return 
         
    find_target(k-init_number, target, '-', len_numbers, depth+1)
    find_target(k+init_number, target, '+', len_numbers, depth+1)

def solution(numbers, target):
    answer = 0
    global init_number

    len_numbers = len(numbers)
    init_number = numbers[0]
    find_target(0, target, '-', len_numbers, 1)
    
    for i in range(len_numbers+2):
        print(stack[i])
    return count

solution(numbers, target)
