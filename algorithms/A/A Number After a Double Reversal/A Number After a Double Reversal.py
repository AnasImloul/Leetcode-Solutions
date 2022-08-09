class Solution(object):
    def isSameAfterReversals(self, num):
		# All you have to do is check the Trailing zeros
        return num == 0 or num % 10  # num % 10 means num % 10 != 0
