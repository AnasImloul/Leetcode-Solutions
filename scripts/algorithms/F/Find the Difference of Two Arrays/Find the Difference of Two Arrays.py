# Runtime: 953 ms (Top 29.31%) | Memory: 14.3 MB (Top 52.22%)
class Solution(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        a = []
        for i in range(len(nums1)):
            if nums1[i] not in nums2:
                a.append(nums1[i])
        b = []
        for i in range(len(nums2)):
            if nums2[i] not in nums1:
                b.append(nums2[i])

        c = [list(set(a))] + [list(set(b))]

        return c