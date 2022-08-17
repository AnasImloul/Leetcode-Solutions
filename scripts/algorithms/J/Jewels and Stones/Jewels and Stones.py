class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
		# 1 : One line solution, My best runtime 38 with 13.9 MB
        return sum(1 for k in stones if k in jewels)
		
		# 2 : Traditional solution
		x=0
		for k in stones:
			if k in jewels:
				x+=1
		return x
