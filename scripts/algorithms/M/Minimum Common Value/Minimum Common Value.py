class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        res=list(set(nums1)& set(nums2))
        if len(res)==0:
            return -1
        else:
            res.sort()
            return res[0]