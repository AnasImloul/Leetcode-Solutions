class Solution:
	def earliestAndLatest(self, n: int, first: int, second: int) -> List[int]:
		def ceiling_of_log2(x: int) -> int:
			""" Return the ceiling of the integer log 2, i.e. index(MSB) - 1 + (1 if x not pow2) """
			assert 0 < x < 0x100000000
			# Use power of 2 test. offset is 1 iff x is NOT a power of 2
			offset = 1 if (x & (x - 1)) != 0 else 0
			x |= (x >> 1)
			x |= (x >> 2)
			x |= (x >> 4)
			x |= (x >> 8)
			x |= (x >> 16)
			# Remove offset to get floor_of_log2. floor(log2(x)) + 1 == ceil(log2(x)) iff x not a power of 2.
			return popcount(x) - 1 + offset

		def popcount(x: int) -> int:
			""" Return the number of set bits in 32 bit unsigned x (Hamming weight) """
			assert 0 <= x < 0x100000000
			x = x - ((x >> 1) & 0x55555555)
			x = (x & 0x33333333) + ((x >> 2) & 0x33333333)
			return (((x + (x >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24

		def count_trailing_zeroes(x: int) -> int:
			""" Return the number of trailing zeroes in 32 bit unsigned x > 0 (LSB + 1). This method is similar to
				branchless binary search, but there are many other methods using the integer log2"""
			assert 0 < x < 0x100000000
			if x & 0x1: return 0  # odd x, quick break
			c = 1
			if (x & 0xffff) == 0:
				x >>= 16
				c += 16
			if (x & 0xff) == 0:
				x >>= 8
				c += 8
			if (x & 0xf) == 0:
				x >>= 4
				c += 4
			if (x & 0x3) == 0:
				x >>= 2
				c += 2
			return c - (x & 0x1)

		# Base case, we can return instantly
		if first + second == n + 1: return [1, 1]

		# This ensures that 'first' is closer to the left than 'second' is to the right.
		# Also, crucially ensures that the sum of first and second is minimal among equivalent configs.
		if first + second >= n + 1: first, second = n + 1 - second, n + 1 - first

		first_plus_second = first + second

		# Special case if first + 1 == second, since we then need to find which round will have an even # of players
		if first + 1 != second and first_plus_second >= (n + 1) // 2 + 1:
			if first_plus_second == n:
				# If n is 4k + 2, first is 2k, and second is 2k+2, then parity of n also matters.
				if n % 4 == 2 and first + 2 == second:
					# Using n // 4 instead of n//4 + 1 because trailing_zeroes(x-1) = rounds until x is even
					ans_earliest = 3 + count_trailing_zeroes(n // 4)
				else:
					ans_earliest = 3 - (first % 2)
			else:
				ans_earliest = 2

		# If we are in a special case: Players are too far left and close together to meet next round
		else:
			ans_earliest = 1 + ceiling_of_log2((n + first_plus_second - 2) // (first_plus_second - 1))
			if first + 1 == second:
				ans_earliest += count_trailing_zeroes(((n + (1 << (ans_earliest-1)) - 1) >> (ans_earliest-1)) - 1)

		# ceiling_of_log2 of n is the number of rounds left until there are exactly 2 players remaining, starting at n.
		# This implicitly assumes that optimal strategy for ans_latest is moving 'first' and 'second' to pos. 1 and 2
		ans_latest = min(ceiling_of_log2(n), n + 1 - second)

		return [ans_earliest, ans_latest]
