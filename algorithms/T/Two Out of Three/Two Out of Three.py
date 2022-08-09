class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        ret = []

        ret += set(nums1).intersection(set(nums2))
        ret += set(nums1).intersection(set(nums3))
        ret += set(nums2).intersection(set(nums3))

        return set(ret)
