class Solution:
    # O(I + W) Time | O(I + W) Space - Where "I" is the first island
    # and "W" is the water to traverse.
    def shortestBridge(self, grid: List[List[int]]) -> int:

        start_row, start_col = self.__get_first_island(grid)

        island_positions = self.__dfs(grid, start_row, start_col, [])

        shortest_bridge = self.__bfs(grid, island_positions)

        return shortest_bridge

    # O(N) Time | O(1) Space
    def __get_first_island(self, grid):
        row_length = len(grid)
        col_length = len(grid[0])

        for row in range(row_length):
            for col in range(col_length):
                if grid[row][col] == 1:
                    return row, col


    # O(N) Time | O(N) Space
    def __dfs(self, grid, row, col, neighbors):
        if row < 0 or row >= len(grid):
            return

        if col < 0 or col >= len(grid[0]):
            return

        if grid[row][col] != 1:
            return

        grid[row][col] = 2
        neighbors.append((row, col))

        self.__dfs(grid, row + 1, col, neighbors)
        self.__dfs(grid, row - 1, col, neighbors)
        self.__dfs(grid, row, col + 1, neighbors)
        self.__dfs(grid, row, col - 1, neighbors)

        return neighbors

    # O(N) Time | O(N) Space
    def __bfs(self, grid, queue):
        steps = 0

        while queue:
            level = []
            for _ in range(len(queue)):
                curr_row, curr_col = queue.pop(0)

                neighbors = self.__get_neighbors(grid, curr_row, curr_col)
                for n_row, n_col in neighbors:

                    if grid[n_row][n_col] == 1:
                        return steps

                    elif grid[n_row][n_col] == 0:
                        grid[n_row][n_col] = -1 # Mark as visited
                        level.append((n_row, n_col))

            queue = level
            steps += 1

        return steps

    # O(1) Time | O(1) Space
    def __get_neighbors(self, grid, row, col):
        row_length = len(grid)
        col_length = len(grid[0])

        up = row - 1 >= 0
        down = row + 1 < row_length
        left = col - 1 >= 0
        right = col + 1 < col_length

        neighbors = []
        if up:
            neighbors.append((row - 1, col))
        if down:
            neighbors.append((row + 1, col))
        if left:
            neighbors.append((row, col - 1))
        if right:
            neighbors.append((row, col + 1))

        return neighbors
