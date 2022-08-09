#pattern
actual    update      ref 
0             0        0
1             1        1
0             1       -1
1             0       -2

class Solution:
	def gameOfLife(self, board: List[List[int]]) -> None:
		r = len(board)
		c = len(board[0])
		ans = [[0]*c for _ in range(r)]
		neighs = [[1,0],[-1,0],[0,1],[0,-1],[-1,-1],[-1,1],[1,1],[1,-1]]

		for i in range(r):
			for j in range(c):
				livecnt,deadcnt = 0,0
				for di,dj in neighs:
					if 0<=(i+di) < r and 0<=(j+dj)<c:
						if board[i+di][j+dj] == 0 or board[i+di][j+dj] == -1 :
							deadcnt+=1
						else:
							livecnt+=1        
				if board[i][j] == 0:
					if livecnt == 3:
						board[i][j] = -1
				else:
					if livecnt == 2 or livecnt==3:
						board[i][j] = 1
					else:
						board[i][j] = -2
		for i in range(r):
			for j in range(c):
				if board[i][j] == -1:
					board[i][j] = 1
				elif board[i][j] == -2:
					board[i][j] = 0
