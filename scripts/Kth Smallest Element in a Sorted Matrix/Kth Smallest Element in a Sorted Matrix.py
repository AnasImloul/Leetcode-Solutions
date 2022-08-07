class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        return sorted(list(sum(matrix, [])))[k-1]