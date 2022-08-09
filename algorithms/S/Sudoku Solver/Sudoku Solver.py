class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        full = set('123456789')
		# lets keep rows, columns and boxes sets in hashmaps
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [[set() for _ in range(3)] for _ in range(3)]
		# and remember empty cell to fill them in
        empty = set()

        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    empty.add((i,j))
                    continue
                rows[i].add(board[i][j])
                cols[j].add(board[i][j])
                boxes[i//3][j//3].add(board[i][j])
                
        def options(i, j):
			"""returns possible options for i,j intersecting options from row, col and box"""
            return (
                (full - rows[i]) &
                (full - cols[j]) &
                (full - boxes[i//3][j//3])
            )

        psingle = True # did we have single option decisions in previos traverse
        while empty:
            single = False # for single option decisions in this traverse
            
            for i, j in deepcopy(empty):
                opts = options(i, j)
                if len(opts) == 0:
					# we've made a wrong assumption - sudoku is unsolvable
                    return None, None
                elif len(opts) == 2 and not psingle: # we have no single-option decisions so have to take an assumption
                    board1 = deepcopy(board)
                    board1[i][j] = opts.pop()
                    board1, empty1 = self.solveSudoku(board1)
                    if board1 != None: # if solved - we're done
                        empty = empty1
                        for i, b1 in enumerate(board1):
                            board[i] = b1 # have to modify initial list, not just replace the reference
                        return board, empty
                if len(opts) == 1: # hey, we have a predetermined choice. nice
                    single = True
                    board[i][j] = opts.pop()
                    empty.remove((i, j))
                    rows[i].add(board[i][j])
                    cols[j].add(board[i][j])
                    boxes[i//3][j//3].add(board[i][j])
                    
            psingle = single

        return board, empty
        ```