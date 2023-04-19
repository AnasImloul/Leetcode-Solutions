class Solution:
	def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
		circle = []
		for x2, y2, radius in queries:
			count = 0
			for x1, y1 in points:
				dis = ((x2-x1)**2+(y2-y1)**2)**0.5 # Use the Distance Formula...
				if dis <= radius:
					count += 1
			circle.append(count)
		return circle