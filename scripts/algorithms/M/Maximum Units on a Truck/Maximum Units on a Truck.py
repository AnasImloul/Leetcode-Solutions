class Solution:
    def maximumUnits(self, B: List[List[int]], T: int) -> int:
        B.sort(key=lambda x: x[1], reverse=True)
        ans = 0
        for b,n in B:
            boxes = min(b, T)
            ans += boxes * n
            T -= boxes
            if T == 0: return ans
        return ans
