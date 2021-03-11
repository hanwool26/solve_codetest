n = 5
dst = [1,3,9,7,5]

def solve(n, dst):
    
    value, cnt, fr = 0, 0, 0
    pre_value, pre_index = 0,0
    org = [0]*n

    while cnt < n:
        value = dst[cnt]

        print('value:', value, 'pre_value:', pre_value, 'pre_index', pre_index)
        org_fr = (pre_value+pre_index)%n
        
        while org[org_fr]!=0:
            org_fr = (org_fr+1) % n
        org[org_fr] = value
        dst[cnt] = 0        
        
        pre_value = value
        pre_index = org_fr
        
        print(f'org[{org_fr}]: {org[org_fr]} value : {value}')
        
        cnt+=1
    
    
    # print('dst', dst)
    return org

def solution(n, dst):
    answer = []
    answer = solve(n, dst)
    
    print(answer)

solution(n, dst)
