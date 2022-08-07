# The question is an awesome example of multi-source bfs.
# The intuition is to add the boundary to a heap if it is 'O'.
# Start the bfs from the nodes added and since you're using queue(FIFO) this bfs will check for inner matrix elements and if they are also 'O' just start
# convertin all these 'O's to 'E's. 
# The last step is to traverse the matrix and if the element is still 'O' turn it to 'X' if it is 'E' turn it to 'O' and we get our answer.
# Pro-Tip -> Try to reduce the number of append operations in python. The lesser the append operations the better is the runtime!
from collections import deque
class Solution:
    def solve(self, bb: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        heap = deque()
        directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
        r, c = len(bb), len(bb[0])
        for i in range(r):
            if bb[i][0] == 'O': heap.append((i, 0))
            if bb[i][c - 1] == 'O': heap.append((i, c - 1))
        for i in range(1, c - 1):
            if bb[0][i] == 'O': heap.append((0, i))
            if bb[r - 1][i] == 'O': heap.append((r - 1, i))
        visited = set()
        def isValid(nr, nc):
            if 0 <= nr < r and 0 <= nc < c: return True
            else: return False
        while heap:
            ri, ci = heap.popleft()
            bb[ri][ci] = 'E'
            for i, j in directions:
                nr, nc = ri + i, ci + j
                if isValid(nr, nc) and (nr, nc) not in visited and bb[nr][nc] == 'O':
                    heap.append((nr, nc))
                    visited.add((nr, nc))
        for i in range(r):
            for j in range(c):
                if bb[i][j] == 'O':
                    bb[i][j] = 'X'
                if bb[i][j] == 'E':
                    bb[i][j] = 'O'
            
