class Solution(object):
	def __init__(self, w):
		"""
		:type w: List[int]
		"""
		#Cumulative sum
		self.list = [0] * len(w)

		s = 0
		for i, n in enumerate(w):
			s += n
			self.list[i] = s


	def pickIndex(self):
		"""
		:rtype: int
		"""
		return bisect_left(self.list, random.randint(1, self.list[-1]))


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
