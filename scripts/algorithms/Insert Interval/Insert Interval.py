class Solution:
	def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

		intervals.append(newInterval)
		intervals.sort(key=lambda x: x[0])

		result = []
		for interval in intervals:
			if not result or result[-1][1] < interval[0]:
				result.append(interval)
			else:
				result[-1][1] = max(result[-1][1],interval[1])

		return result
