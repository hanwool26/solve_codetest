import itertools 

def is_prime(n):
    if n == 0 or n == 1:
        return False
    for i in range(2, n):
        if n%i == 0:
            return False
    return True

print(is_prime(101))

def find_prime(list_num, size):
    prime_list = []
    count = 0
    for i in range(1,size+1):
        combi_num = list(itertools.permutations(list_num, i))
        # print('combi :', combi_num)
        for k in range(len(combi_num)):
            check_num = int(''.join(combi_num[k]))
            if is_prime(check_num) and check_num not in prime_list:
                prime_list.append(check_num)
                count += 1
    # print(prime_list)
    return count    

def solution(numbers):
    answer = 0
    
    a = list(numbers)
    answer = find_prime(numbers, len(numbers))
    return answer
