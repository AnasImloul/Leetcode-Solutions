class Solution:
    def maxDistance(self, n1: List[int], n2: List[int]) -> int:
        i = j = res = 0
        while i < len(n1) and j < len(n2):
            if n1[i] > n2[j]:
                i += 1
            else:
                res = max(res, j - i)
                j += 1
        return res
