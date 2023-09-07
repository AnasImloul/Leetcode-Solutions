# Runtime: 613 ms (Top 70.5%) | Memory: 32.76 MB (Top 92.0%)

class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int], k: int) -> int:
        s = result = 0
        for a, b in zip(nums1, nums2):
            if k == 0: 
                if a-b: return -1
            elif abs(a-b) % k != 0: return -1
            else:
                s += a-b
                if a-b > 0: result += (a-b) // k

        return -1 if s != 0 else result