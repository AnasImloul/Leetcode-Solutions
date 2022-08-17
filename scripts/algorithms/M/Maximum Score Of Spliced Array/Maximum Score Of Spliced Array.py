class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
		nums3 = [0]*n
		nums4 = [0]*n
		for i in range(n):
			nums3[i] = nums1[i]-nums2[i]
			nums4[i] = nums2[i]-nums1[i]
		maxsubseq1 = maxsubseq2 = 0
		v1 = v2 = 0 
		# use kadane algorithm to solve this max subseq problem
		for i in range(n):
			maxsubseq1 = max(maxsubseq1 + nums3[i], nums3[i])
			maxsubseq2 = max(maxsubseq2 + nums4[i], nums4[i])
			v1 = max(v1, maxsubseq1)
			v2 = max(v2, maxsubseq2)
		_sum1 = sum(nums1)
		_sum2 = sum(nums2)
		return max(_sum1 + v2, _sum2 + v1)
