# Target number solution
# Idea 1
def permute(n, r) -> int:
    k = 1
    j = 1
    for _ in range(r):
        k *= n
        j *= r
        n = n-1
        r = r-1
    return int(k/j)
    

def solve(numbers, target):
    answer = 0
    sum = 0
    r=0
    
    for i in numbers:
        sum += i
    
    while True:
        sum -= numbers[0]
        if sum == target:
            break
        elif sum == 0:
            answer = -1
        r += 1
    
    if answer != -1:
        answer = permute(len(numbers), r)
    
    
    return answer
