# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

user_input = int(input())

display = []

for i in range(user_input):
    temp = list(map(int, input().split(' ')))
    display.append(temp)


import itertools
'''
user_input = 4
display = [[2,10], [2,8], [3,4], [4,12]]
'''

minimum = 10000
multiple = 1
num_sum = 0

for i in range(1, user_input+1):
    temp = itertools.combinations(display, i)
    # print(list(temp))
    for i in (temp):
        # print(i)
        for j in i:
            # print(j[0], j[1])
            multiple *= j[0]
            num_sum += j[1]
            
        compare = (multiple - num_sum) if multiple > num_sum else (num_sum - multiple)
        # print('diff', compare, multiple, num_sum)
        multiple = 1
        num_sum = 0
        
        if compare < minimum:
            minimum = compare
            disp_num = len(i)

print(user_input-disp_num)  
