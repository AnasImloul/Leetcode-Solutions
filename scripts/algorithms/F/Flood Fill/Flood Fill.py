class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        queue = deque()
        rows = len(image)
        cols = len(image[0])
        
        targetColor = image[sr][sc]
        
        if color == targetColor:
		    # in this case, we don't need to do anything
            return image

        rDirs = [1, 0, -1, 0]
        cDirs = [0, 1, 0, -1]
        
        queue.append((sr, sc))
        
        while len(queue) > 0:
            r, c = queue.pop()
            
            image[r][c] = color
            for rd, cd in zip(rDirs, cDirs):
                newRow = r + rd
                newCol = c + cd
                
                isValidCoordinate = newRow >= 0 and newRow < rows and newCol >= 0 and newCol < cols
                
                if isValidCoordinate and image[newRow][newCol] == targetColor:
                    queue.append((newRow, newCol))
        
        return image
            
    
