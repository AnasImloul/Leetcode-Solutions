class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        arr = set(arr)
        i = 0
        missed = 0
        while missed != k:
            i += 1
            if i not in arr:
                missed += 1
        return i