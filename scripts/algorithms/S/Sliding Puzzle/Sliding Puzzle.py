# Runtime: 93 ms (Top 39.62%) | Memory: 14.1 MB (Top 16.60%)

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        def findNei(board):
            directs = [[0, 1], [0, -1], [1, 0], [-1, 0]]
            boards = []
            for i in range(2):
                for j in range(3):
                    if board[i][j] == 0:
                        for dr, dc in directs:
                            tmp = [row.copy() for row in board]
                            r, c = i + dr, j + dc
                            if r in range(2) and c in range(3):
                                tmp[r][c], tmp[i][j] = tmp[i][j], tmp[r][c]
                                boards.append(tmp)
            return boards

        visited = set()
        target = [[1, 2, 3], [4, 5, 0]]
        if board == target:
            return 0
        rows, cols = len(board), len(board[0])
        q = collections.deque()
        step = 1

        for row in range(rows):
            for col in range(cols):
                if board[row][col] == 0:
                    boards = findNei(board)
                    for b in boards:
                        if b == target:
                            return step
                        visited.add(tuple([tuple(row) for row in b]))
                        q.append(b)
                    break

        while q:
            step += 1
            for _ in range(len(q)):
                b = q.popleft()
                boards = findNei(b)
                for b in boards:
                    if b == target:
                        return step
                    t = tuple([tuple(row) for row in b])
                    if t not in visited:
                        visited.add(t)
                        q.append(b)

        return -1