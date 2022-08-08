class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n=len(board)
        vis=[0]*(n**2+1)
        board.reverse()
        
        # code for reversing board
        for i in range(len(board)):
            if i%2!=0:
                x=board[i]
                x.reverse()
                board[i]=x
				
        board=sum(board,[]) # this line will convert 2d-array into 1d-array
        
        for i in range(len(board)):
            if board[i]!=-1:
                vis[i+1]=board[i]
                
        q=collections.deque()
        q.append([1,0])
        seen=set()
        while q:
            idx,moves=q.popleft()
            for i in range(1,7):
                next_idx=idx+i
                if vis[next_idx]!=0:
                    next_idx=vis[next_idx]
                if next_idx==(n**2):
                    return (moves+1)
                if next_idx not in seen:
                    seen.add(next_idx)
                    q.append([next_idx,moves+1])
        return -1
