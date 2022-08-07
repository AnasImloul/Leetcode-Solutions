class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        
        # start from i and remove continues ball
        def remove_same(s, i):
            if i < 0:
                return s
            
            left = right = i
            while left > 0 and s[left-1] == s[i]:
                left -= 1
            while right+1 < len(s) and s[right+1] == s[i]:
                right += 1
            
            length = right - left + 1
            if length >= 3:
                new_s = s[:left] + s[right+1:]
                return remove_same(new_s, left-1)
            else:
                return s



        hand = "".join(sorted(hand))

        # board, hand and step
        q = collections.deque([(board, hand, 0)])
        visited = set([(board, hand)])

        while q:
            curr_board, curr_hand, step = q.popleft()
            for i in range(len(curr_board)+1):
                for j in range(len(curr_hand)):
                    # skip the continue balls in hand
                    if j > 0 and curr_hand[j] == curr_hand[j-1]:
                        continue
                    
                    # only insert at the begin of continue balls in board
                    if i > 0 and curr_board[i-1] == curr_hand[j]: # left side same color
                        continue
                    
                    pick = False
                    # 1. same color with right
                    # 2. left and right are same but pick is different
                    if i < len(curr_board) and curr_board[i] == curr_hand[j]:
                        pick = True
                    if 0<i<len(curr_board) and curr_board[i-1] == curr_board[i] and curr_board[i] != curr_hand[j]:
                        pick = True
                    
                    if pick:
                        new_board = remove_same(curr_board[:i] + curr_hand[j] + curr_board[i:], i)
                        new_hand = curr_hand[:j] + curr_hand[j+1:]
                        if not new_board:
                            return step + 1
                        if (new_board, new_hand) not in visited:
                            q.append((new_board, new_hand, step+1))
                            visited.add((new_board, new_hand))

        return -1
