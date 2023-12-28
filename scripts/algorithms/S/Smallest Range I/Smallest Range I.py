// Runtime: 156 ms (Top 5.06%) | Memory: 18.40 MB (Top 7.47%)

class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        maxi = max(A)
        mini = min(A)
        return max(0, maxi-K-mini-K)
