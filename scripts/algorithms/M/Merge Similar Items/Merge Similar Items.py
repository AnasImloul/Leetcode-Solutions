class Solution:
	"""
	Time:   O((n+m)*log(n+m))
	Memory: O(n+m)
	"""

	def mergeSimilarItems(self, first: List[List[int]], second: List[List[int]]) -> List[List[int]]:
		merged = defaultdict(int)

		for value, weight in first + second:
			merged[value] += weight

		return sorted(merged.items())