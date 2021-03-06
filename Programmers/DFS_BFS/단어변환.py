def find_one_word_match(origin, compared):
    count = 0;
    # print('origin', origin, 'compared', compared)
    for i in range(len(origin)):
        if count > 2:
            return False
        # print('origin[]', origin[i], 'compared[]', compared[i])
        if origin[i] != compared[i]:
            count+=1
            
    return True if count == 1 else False

def find_target(dict, begin, target, size):
    step = 0
    is_find = False
    for key, values in dict.items():
        for i in values:
            if find_one_word_match(begin, i) == True:
                begin = i
                step += 1
                print('step', begin)
                if begin == target:
                    is_find = True
                    break
    return step if is_find == True else 0

def solution(begin, target, words):
    word_dict = {}
    answer = 0
    temp = [[] for _ in range(len(begin))]
    for i in range(len(begin)):       
        for j in words:
            # print(target[i], j[i])
            if target[i] == j[i]:
                temp[i].append(j)
        word_dict[target[i]] = temp[i]
   
    #print('result', word_dict)
    answer = find_target(word_dict, begin, target, len(words))
    return answer
