def solution():
    user_input = input()
    cnt = 0
    sum = 0

    num_len = int(user_input)
    # print ("Hello Goorm! Your input is " + user_input)
    building = []*num_len
    while cnt < num_len:
        user_input = input()
        building.append(int(user_input))
        cnt+=1
    
    # print(building)
    
    cnt = 0
    while cnt < num_len:
        base = building[cnt]
        for i in range(cnt+1, num_len):
            # print('base', base, 'building', building[i])
            if base > building[i]:
                sum += 1
            else:
                break
        cnt+=1    
    print(sum)
		
solution()
