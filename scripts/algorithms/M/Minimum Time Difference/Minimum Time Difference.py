class Solution:
	def findMinDifference(self, timePoints: List[str]) -> int:
		timePoints.sort()

		def getTimeDiff(timeString1, timeString2):
			time1 = int(timeString1[:2]) * 60 + int(timeString1[3:])
			time2 = int(timeString2[:2]) * 60 + int(timeString2[3:])

			minDiff = abs(time1 - time2)

			return min(minDiff, 1440 - minDiff)

		result = getTimeDiff(timePoints[0], timePoints[-1]) # edge case, we need to check minDiff of first and last time after sorting

		for i in range(len(timePoints)-1):
			curMin = getTimeDiff(timePoints[i], timePoints[i+1])

			if curMin < result:
				result = curMin

		return result
		