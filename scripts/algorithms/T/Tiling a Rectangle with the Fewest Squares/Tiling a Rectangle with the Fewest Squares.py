# Runtime: 197 ms (Top 21.3%) | Memory: 16.48 MB (Top 34.6%)

class Solution:
    def tilingRectangle(self, n: int, m: int) -> int:
      # try brute force backtracking?
      board = [[0 for _ in range(n)] for _ in range(m)]

      ans = math.inf
      def bt(counts):
        nonlocal ans
        if counts >= ans:
          return
        
        pos = None
        found = False
        for row in range(m):
          for col in range(n):
            if board[row][col] == 0:
              pos = (row, col)
              found = True
              break
          if found:
            break
        if not found:
          ans = min(ans, counts)
          return

        # see how many difference size of squares we can place from this spot
        r, c = pos
        offset = 0
        while r + offset < m and c + offset < n and board[r + offset][c] == 0 and board[r][c + offset] == 0:
          offset += 1
        # max can place size is offset
        for row in range(r, r + offset):
          for col in range(c, c + offset):
            board[row][col] = 1
        # do bt and shrink
        while offset > 0:
          bt(counts + 1)
          # shrink
          for row in range(r, r + offset):
            board[row][c + offset - 1] = 0
          for col in range(c, c + offset):
            board[r + offset - 1][col] = 0
          offset -= 1

      bt(0)
      return ans