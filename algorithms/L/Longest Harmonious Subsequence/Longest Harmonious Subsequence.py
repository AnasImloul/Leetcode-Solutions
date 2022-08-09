""
from collections import Counter
class Solution:
	def findLHS(self, nums: List[int]) -> int:
		counter=Counter(nums)
		# values=set(nums)
		res=0
		# if len(values)==1:return 0
		for num in nums:
			if num+1 in counter or num-1 in counter:
				res=max(res,counter[num]+counter.get(num+1,0))
				res=max(res,counter[num]+counter.get(num-1,0))

		return res
""