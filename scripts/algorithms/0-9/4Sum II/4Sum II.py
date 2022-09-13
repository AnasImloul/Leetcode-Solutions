# Runtime: 1360 ms (Top 29.95%) | Memory: 14.2 MB (Top 70.39%)
class Solution:
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        n1n2 = defaultdict(int)
        for n1 in nums1:
            for n2 in nums2:
                n1n2[n1+n2] += 1
        n3n4 = defaultdict(int)
        for n3 in nums3:
            for n4 in nums4:
                n3n4[n3+n4] += 1
        ans = 0
        for s in n1n2:
            ans += n1n2[s] * n3n4[-s]
        return ans