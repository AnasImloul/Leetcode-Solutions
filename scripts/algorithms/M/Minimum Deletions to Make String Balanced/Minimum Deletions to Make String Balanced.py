class Solution:
	def minimumDeletions(self, s: str) -> int:
		preSum = [0] * (len(s) + 1)
		sufSum = [0] * (len(s) + 1)

		for i in range(len(s)):
			if s[i] == "a":
				preSum[i] += 1 + preSum[i-1]

			else:
				preSum[i] = preSum[i-1]

			if s[len(s)-i-1] == "b":
				sufSum[len(s)-i-1] += 1 + sufSum[len(s)-i]

			else:
				sufSum[len(s)-i-1] += sufSum[len(s)-i]

		maxStringLength = 0
		for i in range(len(s)):
			if preSum[i] + sufSum[i] > maxStringLength:
				maxStringLength = preSum[i] + sufSum[i]

		return len(s) - maxStringLength