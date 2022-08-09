class Solution:
	def largestMultipleOfThree(self, digits: List[int]) -> str:
		A = digits
		A.sort()
		A.reverse()

		@cache
		def DP(i, r): # max number whose remainder is r using subarray [0:i] (inclusive) 
			if i == 0:
				if A[0] % 3 == r:
					return A[0]
				else:
					return 0

			Ra = DP(i-1, r)
			Rb = [ x for j in range(3) \
				  for x in ( DP(i-1,j) * 10 + A[i] ,)
				  if x % 3 == r ]

			return max([Ra, *Rb])

		ans = DP(len(A) - 1, 0)

		if ans == 0 and 0 not in A:
			return ""
		else:
			return str(ans)
