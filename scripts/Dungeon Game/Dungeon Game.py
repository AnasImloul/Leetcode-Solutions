class Solution:


	def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:

		dp = defaultdict(lambda: inf)
		dp[(len(dungeon), len(dungeon[0]) - 1)] = 1

		for i in range(len(dungeon) - 1, -1, -1):

			for j in range(len(dungeon[0]) - 1, -1, -1):

				dp[(i, j)] = min(dp[(i + 1, j)], dp[(i, j + 1)]) - dungeon[i][j]

				if dp[(i, j)] <= 0:
					dp[(i, j)] = 1

		return dp[(0, 0)]