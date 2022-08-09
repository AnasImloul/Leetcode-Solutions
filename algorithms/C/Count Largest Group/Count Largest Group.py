def compute(num):
	if num < 10:
		return num

	newVal = 0

	while num > 0:
		last = num % 10
		newVal += last
		num /= 10

	return newVal

class Solution(object):
	def countLargestGroup(self, n):
		"""
		:type n: int
		:rtype: int
		"""
		myMap = {}

		for i in range(1, n + 1):
			val = compute(i)

			if val in myMap.keys():
				myMap.get(val).append(i)
			else:
				myMap[val] = [i]

		maxLen = 0

		for n in myMap.values():
			maxLen = max(maxLen, len(n))

		ans = 0

		for n in myMap.values():
			if len(n) == maxLen:
				ans += 1

		return ans
