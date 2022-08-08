class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        m, n = len(seats), len(seats[0])
        match = [[-1]*n for _ in range(m)]
        def dfs(i, j, visited):
            for x, y in [(i-1,j-1),(i-1,j+1),(i,j-1),(i,j+1),(i+1,j-1),(i+1,j+1)]:
                if 0 <= x < m and 0 <= y < n and seats[x][y] == "." and (x, y) not in visited:
                    visited.add((x, y))
                    if match[x][y] == -1 or dfs(*match[x][y], visited):
                        match[x][y] = (i, j)
                        match[i][j] = (x, y)
                        return True
            return False
        def max_matching():
            cnt = 0
            for i in range(m):
                for j in range(0,n,2):
                    if seats[i][j] == '.' and match[i][j] == -1:
                        visited = set()
                        cnt += dfs(i, j, visited)
            return cnt
		#returns the number of elements of the maximum independent set in the bipartite set
        return sum(seats[i][j]=='.' for i in range(m) for j in range(n)) - max_matching()