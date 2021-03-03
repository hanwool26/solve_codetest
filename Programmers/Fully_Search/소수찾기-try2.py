import itertools 
import math

def is_prime(n):
    n_sqrt = int(math.sqrt(n)+1) # 제곱근으로 계산해도 소수 구하기에서 동일한 값이 나옴 제곱근보다 큰 수로 나누기는 의미가 없음.
    if n == 0 or n == 1:
        return False
    for i in range(2, n_sqrt):
        if n%i == 0:
            return False
    return True

def find_prime(list_num, size):
    prime_list = []
    count = 0
    for i in range(0,size):
        combi_num = list(itertools.permutations(list_num, i+1)) # 순열 함수, 조합 함수는 itertools.combinations(p,r)
        # print('combi :', combi_num)
        for k in combi_num:
            check_num = int(''.join(k))
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
