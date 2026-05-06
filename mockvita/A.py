from collections import deque

dir = [(-1 , 0)  , (1 , 0) , (0 ,-1) , (0 , 1)]

def is_valid(x , y , N , M):
    return 0<=x <N and 0 <= y <M

def simulate_gra(start_x , start_y , matrix , N , M):
    """simulate untill"""
    while start_x + 1 < N and matrix[start_x +1][start_y] !='B':
        start_x+=1
    return start_x


def bfs (start_x , start_y , matrix , N , M , K):
    queue = deque([(start_x , start_y , 0)])
    visited = set()
    visited.add(start_x ,start_y)
    
    reachable_cell = []
    
    while queue :
        x , y , move = queue.popleft()
        
        if matrix[x][y] == 'E' and x != N-1:
            reachable_cell.append((x ,y , move))
            
        if move >= K:
            continue
        
        for dx , dy in dir:
            nx , ny = x + dx , y + dy
            if is_valid(nx  , ny , N , M ) and (nx , ny) not in visited:
                if matrix[nx][ny] != 'B':
                    visited.add((nx  , ny))
                    queue.append((nx , ny , move+1))
                    
    return reachable_cell

def fast_reach (N , M , matrix , K):
    
    start_x  = start_y =-1;
    for i in range(N):
        for j in range(M):
            if matrix[i][j] == 'S':
                start_x , start_y  = i , j
                break
            
        if start_x !=-1:
            break
    start_x = simulate_gra(start_x , start_y , matrix , N , M)
    
    reachable_cell = bfs(start_x , start_y , matrix , N , M, K)
    
    
    fast_dis = -1
    
    fast_cell = []
    
    for x , y  , move in reachable_cell:
        manhanttan_distance = abs(x - start_x) + abs(y - start_y)
        
        if manhanttan_distance > fast_dis:
            fast_dis = manhanttan_distance
            fast_cell = [(x ,y)]
        elif manhanttan_distance == fast_dis:
            fast_cell .append((x, y))
            
    return fast_cell

def main():
    
    N , M = map(int  , input().strip().split())
    matrix = [input().strip().split()  for _ in range (N)]
    k = int(input().strip())
    
    farth_cell = fast_reach(N , M ,matrix , K)
    
    for x , y in farth_cell: 
        print( x , y)
        
if __name__ =="__main__":
    main()
    
    