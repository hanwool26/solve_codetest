def find_max(number, k, answer, index):
    max = -1
    next_index = 0
    remain = len(number)-k+1

    # print('number', number, 'k:', k, 'remain', remain)
    if any(number) != True or k == 0:
        return

    for i in range(index, remain):        
        if int(number[i]) > max:
            max = int(number[i])
            next_index = i
        if int(number[i]) == 9:
            max = int(number[i])
            next_index = i 
            break

    answer.append(max)
    find_max(number, k-1, answer, next_index+1)

def solution(number, k):
    answer = ''
    list_number = list(number)
    list_answer = []    
    
    find_max(list_number, len(number)-k, list_answer, 0)
    answer = ''.join(map(str,list_answer))  
    # print(answer)
    return answer
