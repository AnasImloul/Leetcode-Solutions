from queue import PriorityQueue
class Solution:
	def smallestRange(self, nums: List[List[int]]) -> List[int]:
		q = PriorityQueue()
		maxi = -10**7
		mini = 10**7
		for i in range(len(nums)):
			maxi = max(maxi,nums[i][0])            
			mini = min(mini,nums[i][0])
			q.put((nums[i][0],i,0))  

		s, e = mini, maxi
		while not q.empty() :
			mini, i, j = q.get()
			if maxi - mini < e-s:
				s,e = mini, maxi
			if j+1 < len(nums[i]):
				maxi = max(maxi,nums[i][j+1])
				q.put((nums[i][j+1],i,j+1))
			else: break
		return [s,e]