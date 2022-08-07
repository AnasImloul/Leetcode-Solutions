class Solution:
	def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
		n = len(people)
		people.sort()
		ans = [[]]*n
		i = 0
		while people:
			h,p = people.pop(0)
			count= p
			for i in range(n):
				if count== 0 and ans[i] == []:
					ans[i] = [h,p]
					break

				elif not ans[i] or (ans[i] and ans[i][0] >= h ):
					count -= 1
		return ans