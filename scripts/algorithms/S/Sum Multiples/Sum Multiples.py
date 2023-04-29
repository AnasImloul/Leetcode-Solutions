class Solution:
    def sumOfMultiples(self, n: int) -> int:
        res = 0
		#  iterate through the range 1 to n and 
        for i in range(3, n + 1):
			# count numbers divisible by either 3, 5, or 7
            if i % 3 == 0 or i % 5 == 0 or i % 7 == 0:
                res += i
        return res