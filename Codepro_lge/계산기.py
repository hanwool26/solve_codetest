char_to_ord = 55
num_to_ord = 48

def multiple_B(num, flag, B):
    i = 100
    answer = ('-' if flag == 1 else '')
    # print('num', num)
    for index in range(100, 0, -1):
        
        quotient = num // (B**index)
        num = num % (B**index)
        # print('index', index, 'quota', quotient, 'remain', num)
        if quotient >=10:
            answer += chr(quotient+char_to_ord)
        elif 0<quotient <= 9:
            answer += chr(quotient+num_to_ord)
        
        if index == 1:
            if num >=10:
                answer += chr(num+char_to_ord)
            elif 0<num <= 9:
                answer += chr(num+num_to_ord)
    
    return answer if answer != None else '0'
    
def solution(test_num):
    # test_case = int(input())
    # print('solution', test_num)
    cnt = 0
    offset = 0
    Byte = int(test_num[0])
    flag = 0
    toten_array = []
    
    index = 0 # len(test_num[1])
    for j in range(1,len(test_num)):
        sum = 0
        index = 0
        for i in range(len(test_num[j])-1, -1, -1):
            num = (test_num[j][i])
            if num == '-':
                flag += 1
                index += 1
                continue
            if ord(num) <= ord('9'):
                offset = num_to_ord
            else:
                offset = char_to_ord

            toten = ord(num)-offset
            value = int((Byte**index) * toten)
            # print('value', value)
            index+=1
            sum += value
        toten_array.append(sum)
    # print(toten_array)
    
    num = 1
    for i in toten_array:
        num *= i
    
    print(multiple_B(num, flag, Byte) if num !=0 else '0')

user_input = input()
cnt = 0
numbers = []

while cnt < int(user_input):
    input_number = list((map(str, input().split(' '))))
    numbers.append(input_number)
    cnt += 1
 
for i in numbers:
    solution(i)
