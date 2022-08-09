class Solution:
    def diagonalSort(self, A: List[List[int]]) -> List[List[int]]:
        n, m, d = len(A), len(A[0]), defaultdict(list)
        any(d[i - j].append(A[i][j]) for i in range(n) for j in range(m))
        any(d[sum_].sort(reverse=1) for sum_ in d)
        return [[d[i-j].pop() for j in range(m)] for i in range(n)]