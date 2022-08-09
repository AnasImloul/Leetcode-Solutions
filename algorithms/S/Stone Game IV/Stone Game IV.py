class Solution:
    def winnerSquareGame(self, n: int) -> bool:
        dyp = [False] * (n + 1)
        sqrs = []
        currSqr = 1
        for i in range(1, n + 1):
            if i == currSqr * currSqr:
                sqrs.append(i)
                currSqr += 1
                dyp[i] = True
            else:
                for sqr in sqrs:
                    if not dyp[i - sqr]:
                        dyp[i] = True
                        break
        return dyp[n]
	```
	
	### Thank You!