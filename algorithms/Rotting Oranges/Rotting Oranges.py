class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        visited = set()
        res = 0
        def bfs(grid):
            que = collections.deque()
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 2:
                        que.append((i,j))
            que.append(None)
            count = 0    
            while len(que)>0:
                left , right = 0,0
				# This other while loop is to make sure that we traverse from all the rotten oranges in one turn.
                while que[0] != None:
                    r,c = que.popleft()
                    for Cols in [-1,1]:
                        if c+Cols>=0 and c+Cols<len(grid[0]) and grid[r][c+Cols]==1:
                            grid[r][c+Cols] = 2
                            left += 1
                            que.append((r,c+Cols))
                    
                    for Rows in [-1,1]:
                        if r+Rows>=0 and r+Rows<len(grid) and grid[r+Rows][c]==1:
                            grid[r+Rows][c] = 2
                            right += 1
                            que.append((r+Rows,c))
				'''
				if either left or right or both is incremented it means that we have moved in either direction,
				and then this will be counted as a turn(or minute as per the problem description.).
				
				'''
                if left is not 0 or right is not 0:
                    count+=1
                que.popleft()
                if len(que)>0:
				    '''
				    This is required to terminate the loop and prevent infinite loop.
				    This only appends a None if there is still some values in the que, 
				    else we have completed our traversal and we can stop going any futher.
				    '''
                    que.append(None)
            return count
        res = bfs(grid)
        for i in range(len(grid)):
                for j in range(len(grid[0])):
                    if grid[i][j] == 1:
                        return -1
        return res
