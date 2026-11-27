# Runtime: 3 ms (Top 97.45%) | Memory: 19.10 MB (Top 88.85%)

class Solution:
    def findIntersectionValues(self, nums1: List[int], nums2: List[int]) -> List[int]:
        set1 = set(nums1)
        set2 = set(nums2)

        count1 = sum(1 for num in nums1 if num in set2)
        count2 = sum(1 for num in nums2 if num in set1)

        return [count1, count2]
