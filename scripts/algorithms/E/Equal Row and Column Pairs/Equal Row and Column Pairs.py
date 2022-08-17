class Solution:
	def equalPairs(self, grid: List[List[int]]) -> int:
		# Get the Size of the Grid
		n = len(grid)

		# Radix Sort the Row/Column Indecies (maintaining the Separate buckets) - O(n^2)
		# positions are stored as a tuple containing: (direction, row index, column index)
		positions = [(0, i, 0) for i in range(n)] # all starting row positions
		positions.extend((1, 0, j) for j in range(n)) # all starting column positions
		oldBuckets = [positions]
		for k in range(n):
			# Split the Current Buckets Into New Buckets
			buckets = []
			for bucket in oldBuckets:
				# Split the Current Bucket Into New Buckets
				bucketMap = defaultdict(list)
				for d, i, j in bucket:
					# Add the Next Position to its Respective Bucket Based on the Current Position
					bucketMap[grid[i][j]].append((d, i + d, j + 1 - d))

				# Add the New Buckets to the List of Buckets (pruning buckets with no pairs) - O(n)
				buckets.extend(x for x in bucketMap.values() if len(x) > 1)

			# Update the Buckets
			oldBuckets = buckets

		# Count the Number of Rows/Columns in Each Bucket - O(n)
		pairs = 0
		for bucket in buckets:
			# Count the Number of Rows/Columns in the Current Bucket
			rows = 0
			cols = 0
			for d, i, j in bucket:
				# Check if the Position is From a Column or a Row
				if d:
					cols += 1
				else:
					rows += 1

			# Count the Number of Pairs That Contributes
			pairs += rows * cols

		# Return the Total Number of Pairs
		return pairs
