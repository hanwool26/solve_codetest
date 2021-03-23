# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
import sys
N = int(input())
array = list(map(int, sys.stdin.readline().split()))

sum = 0

def find_min_max(array, front, end):
    global sum
    min_index = front
    min_value = float('inf')
    max_index = end
    max_value = 0
    for index in range(front, end):
        if array[index] < min_value:
            min_value = array[index]
            min_index = index
        if array[index] > max_value:
            max_value = array[index]
            max_index = index
    # print(max_value, min_value)
    if front == 0 and max_index < min_index:
        sum+= max_value
    if max_index <= min_index:
        return
    
    sum += max_value
    sum -= min_value
    # print(min_value, max_value, min_index, max_index)
    find_min_max(array, max_index+1, end)
    find_min_max(array, front, min_index)

find_min_max(array, 0, len(array))
print(sum)
