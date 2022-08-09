class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # Purpose: find the cells that allow rain flow into the ocean
        # Method: DFS
        # Intuition: start from each border, check cell and neb, if OK, append to res
            
        # init: res, vis (pac, atl), ROW, COL
        res = []
        pac = set()
        atl = set()
        ROW = len(heights)
        COL = len(heights[0])

        # top and bottom row
        for col in range(COL):
            self.dfs(0, col, pac, heights[0][col], heights)
            self.dfs(ROW-1, col, atl, heights[ROW-1][col], heights)

        # left and right col
        for row in range(ROW):
            self.dfs(row, 0, pac, heights[row][0], heights)
            self.dfs(row, COL-1, atl, heights[row][COL-1], heights)

        # append to res
        for row in range(ROW):
            for col in range(COL):
                if (row, col) in pac and (row, col) in atl:
                    res.append([row, col])

        # return
        return res

    
    def dfs(self, row, col, vis, prev, heights):
        # hard-code definition
        try:
            cur = heights[row][col]
        except:
            pass

        # inbound, unvisited, increase from ocean
        if (0<=row<len(heights) and 0<=col<len(heights[0])) \
            and (cur >= prev) \
                and ((row, col) not in vis):

            # add to visited 
            vis.add((row, col))

            # check nebs
            self.dfs(row+1, col, vis, cur, heights)
            self.dfs(row-1, col, vis, cur, heights)
            self.dfs(row, col+1, vis, cur, heights)
            self.dfs(row, col-1, vis, cur, heights)

