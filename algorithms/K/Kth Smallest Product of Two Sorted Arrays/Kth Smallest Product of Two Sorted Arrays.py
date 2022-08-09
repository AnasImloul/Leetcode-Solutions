class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        result = []
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                temp = nums1[i]*nums2[j]
                result.append(temp)
        result.sort()
        return result[k-1]
