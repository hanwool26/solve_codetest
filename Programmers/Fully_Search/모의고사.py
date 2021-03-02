def solution(answers):
    pick_answer = [[1,2,3,4,5],
              [2,1,2,3,2,4,2,5],
              [3,3,1,1,2,2,4,4,5,5,]]
    answer = []
    max_index = []
    
    for index in range(3):
        num_of_answer = 0
        for count, i in enumerate(answers):
            j = count % len(pick_answer[index])
            
            if pick_answer[index][j] == i:
                num_of_answer += 1
                print(pick_answer[index][j], i)
                
        answer.append(num_of_answer)
    
    max_index = [i+1 for i,v in enumerate(answer) if v == max(answer)]
    # print('choose_max_index :', max_index)
    return max_index
