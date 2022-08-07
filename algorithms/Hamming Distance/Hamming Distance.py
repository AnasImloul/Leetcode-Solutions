class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
		# First, using XOR Bitwise Operator, we take all distinct set bits.
        z = x ^ y
		# We inicialize our answer with zero.
        ans = 0
		# Iterate while our z is not zero.
        while z:
			# Every iteration we add one to our answer.
            ans += 1
			# Using the expression z & (z - 1), we erase the lowest set bit in z.
            z &= z - 1
        return ans
