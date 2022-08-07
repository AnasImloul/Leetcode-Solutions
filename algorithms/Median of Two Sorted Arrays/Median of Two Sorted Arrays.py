class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        lis = nums1 + nums2
        lis.sort()
        hi = len(lis)
        print(5/2)
        if hi%2 == 0:
            if (lis[hi/2] + lis[hi/2-1])%2 == 0:
                return (lis[hi/2] + lis[hi/2-1] )/2
            return (lis[hi/2] + lis[hi/2-1])/2 + 0.5
        else:
            return lis[hi//2]
