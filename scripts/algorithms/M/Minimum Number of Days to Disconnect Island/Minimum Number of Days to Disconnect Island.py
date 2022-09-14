# Runtime: 170 ms (Top 85.91%) | Memory: 15.7 MB (Top 23.94%)
class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        cnt = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j]:
                    cnt += 1 # count the number of elements
                    root = (i, j) # assign the root node for the graph

        if cnt <= 1 : return cnt # no elements in the map

        vis, low, time, res = {root}, {}, {}, []

        # find whether articulation points are present in the matrix
        def articulation_points(curr, parent):
            low[curr] = time[curr] = len(vis)
            children = 0
            i, j = curr

            for x, y in [(i+1, j), (i-1, j), (i, j+1), (i, j-1)]:
                if (x, y) == parent : continue

                if 0<=x<len(grid) and 0<=y<len(grid[0]) and grid[x][y]:
                    if (x, y) not in vis:
                        vis.add((x,y))
                        articulation_points((x,y), curr)
                        low[curr] = min(low[curr], low[(x, y)])
                        children += 1
                        if low[(x, y)] >= time[(curr)] and parent!=(-1, -1):
                            res.append([i, j])
                    else:
                        low[curr] = min(low[curr], time[(x, y)])

                if parent == (-1, -1) and children > 1:
                    res.append([x, y])

        articulation_points(root, (-1, -1))

        if len(vis) != cnt: # if the matrix is disconnected beforehand
            return 0
        elif res: # if there are any articulation points
            return 1
        else: # worst case, no articulation points
            return 2
