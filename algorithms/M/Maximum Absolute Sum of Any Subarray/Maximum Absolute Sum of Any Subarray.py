class Solution:
	def maxAbsoluteSum(self, A):

		ma,mi,res = 0,0,0
		for a in A:
			ma = max(0,ma+a)
			mi = min(0,mi+a)
			res = max(res,ma,-mi)
		return res
