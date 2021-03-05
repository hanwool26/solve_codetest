from collections import deque

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

def solution(begin, target, words):
    answer = 0
    visited = []
    queue = deque([begin])

    while queue:
        if target in queue:
            break
        begin = queue.popleft()
        answer += 1
        
        temp = words.copy()
        for i in words:
            if i not in visited and find_one_word_match(begin, i):
                visited.append(i)
                queue.append(i)

    if answer > len(words):
        answer = 0

    return answer
