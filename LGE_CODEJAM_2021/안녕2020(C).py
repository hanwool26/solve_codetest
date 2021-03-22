temp = []

def find_hello(pair):
    pair = str(pair)
    # print(pair[0:4], pair[-4:])
    if '2020' == pair[0:4] and '2021' == pair[-4:]:
        return 1
    return 0
    
def find_pair(sample):
    pair_num = 0
    for i in range(len(sample)-1):
        for j in range(i+1, len(sample)):
            pair = sample[i] + sample[j]
            pair_num += find_hello(pair) 
    print(pair_num)
            
N = int(input())
T = int(input())
for i in range(N):
    # T = int(input())
    temp.append(list(map(int, input().split(' '))))
    
for i in temp:
    find_pair(i)
