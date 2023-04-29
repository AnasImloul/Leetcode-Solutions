class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        
        # creating a borad map to loop-up the square value
        board_map = {}
        i = 1
        b_rev = board[::-1]
        for d, r in enumerate(b_rev):
			# reverse for even rows - here d is taken as direction 
            if d%2 != 0: r = r[::-1] 
            for s in r:
                board_map[i] = s
                i += 1
        
        # BFS Algorithm
        q = [(1, 0)] # (curr, moves)
        v = set()
        goal = len(board) * len(board) # end square
        
        while q:
            curr, moves = q.pop(0)
            # win situation
            if curr == goal: return moves
            # BFS on next 6 places (rolling a die)
            for i in range(1, 7):
                # skip square outside board
                if curr+i > goal: continue
                # get value from mapping
                next_pos = curr+i if board_map[curr+i] == -1 else board_map[curr+i]
                if next_pos not in v:
                    v.add(next_pos)
                    q.append((next_pos, moves+1))
        
        return -1
 