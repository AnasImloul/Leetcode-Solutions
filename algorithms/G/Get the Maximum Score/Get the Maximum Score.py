from itertools import accumulate
class Solution:
    def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
        acc1 = list(accumulate(nums1, initial = 0))
        acc2 = list(accumulate(nums2, initial = 0))
        i, j = len(nums1)-1, len(nums2)-1
        previ, prevj = len(nums1), len(nums2)
        prev_maxscore = 0
        while i >= 0 and j >= 0:
            while i >= 0 and j >= 0 and nums1[i] < nums2[j]:
                j -= 1
            if i >= 0 and j >= 0 and nums1[i] == nums2[j]:
                prev_maxscore += max(acc1[previ]-acc1[i], acc2[prevj]-acc2[j])
                previ, prevj = i, j
                i -= 1
                j -= 1
            while i >= 0 and j >= 0 and nums2[j] < nums1[i]:
                i -= 1
            if  i >= 0 and j >= 0 and nums1[i] == nums2[j]:
                prev_maxscore += max(acc1[previ]-acc1[i], acc2[prevj]-acc2[j])
                previ, prevj = i, j
                i -= 1
                j -= 1
        prev_maxscore += max(acc1[previ]-acc1[0], acc2[prevj]-acc2[0])
        return prev_maxscore % (10**9 + 7)
