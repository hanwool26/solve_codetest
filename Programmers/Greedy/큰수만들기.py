def find_max(number, k, answer, index):
   
    # print(number, 'k:', k, 'index:', index)
    max = 0
    next_index = 0
    remain = len(number)-k+1

    if any(number) != True:
        return

    for i in range(index, remain):        
        if int(number[i]) > max:
            max = int(number[i])
            next_index = i
            
    answer.append(max)
    number = number[next_index+1:]
    # print('number', number)

    if k == 0:
        return

    find_max(number, k-1, answer, 0)

def solution(number, k):
    answer = ''
    list_number = list(number)
    list_answer = []    
    
    find_max(list_number, len(number)-k, list_answer, 0)
    answer = ''.join(map(str,list_answer))    
    return answer
