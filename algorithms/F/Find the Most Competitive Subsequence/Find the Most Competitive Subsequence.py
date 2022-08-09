class Solution:
	def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
		end = len(nums) - k
		ans = []
		for num in nums:
			while end and ans and num < ans[-1] :
				ans.pop()
				end -= 1
			ans.append(num)
		
		return ans[:k]