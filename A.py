def solve(input_file: str) -> str:
    dir = {
        '═': [(0, 1), (0, -1)],  
        '║': [(1, 0), (-1, 0)],  
        '╔': [(1, 0), (0, 1)],   
        '╗': [(1, 0), (0, -1)],  
        '╚': [(-1, 0), (0, 1)],  
        '╝': [(-1, 0), (0, -1)], 
        '╠': [(1, 0), (-1, 0), (0, 1)],  
        '╣': [(1, 0), (-1, 0), (0, -1)], 
        '╦': [(0, 1), (0, -1), (1, 0)],  
        '╩': [(0, 1), (0, -1), (-1, 0)]  
    }
    
    all_directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    
    st_x = 0
    st_y = 0
    
    mx_x = 0
    mx_y = 0
    
    with open(input_file, 'r', encoding='utf-8') as file:
        lines = file.readlines()
        
    for line in lines:
        parts = line.strip().split()
        if len(parts) == 3:
            obj, x, y = parts
            mx_x = max(mx_x, int(x))
            mx_y = max(mx_y, int(y))
    
    vis = [[False for _ in range(mx_y+5)] for _ in range(mx_x+5)]
    grid = [[' ' for _ in range(mx_y+5)] for _ in range(mx_x+5)]
    ans = []
        
    for line in lines:
        parts = line.strip().split()
        if len(parts) == 3:
            obj, x, y = parts
            if obj == '*':
                st_x = int(x)
                st_y = int(y)
                
            x, y = int(x), int(y)
            grid[x][y] = obj
            
            
    def dfs(x: int, y: int):
        vis[x][y] = True
    
        for dx, dy in dir.get(grid[x][y], []):
            chx, chy = x + dx, y + dy
            
            if chx < 0 or chx >= mx_x or chy < 0 or chy >= mx_y:
                continue
            
            if vis[chx][chy]:
                continue
            
            if grid[chx][chy].isalpha():
                ans.append(grid[chx][chy])
                
                for adx, ady in all_directions:
                    nchx, nchy = chx + adx, chy + ady
                    if 0 <= nchx < mx_x and 0 <= nchy < mx_y and not vis[nchx][nchy]:
                        dfs(nchx, nchy)
                continue
            
            p = (-dx, -dy)
            
            if p in dir.get(grid[chx][chy], []):
                dfs(chx, chy)
    
    for dx, dy in all_directions:
        p = (-dx, -dy)
        
        chx, chy = st_x + dx, st_y + dy
        
        if chx < 0 or chx >= mx_x or chy < 0 or chy >= mx_y:
            continue
        
        if vis[chx][chy]:
            continue
        
        if p in dir.get(grid[chx][chy], []):
            dfs(chx, chy)
    
    return ''.join(sorted(set(ans)))