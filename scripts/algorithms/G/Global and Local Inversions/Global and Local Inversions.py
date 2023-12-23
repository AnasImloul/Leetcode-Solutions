// Runtime: 620 ms (Top 99.42%) | Memory: 31.10 MB (Top 5.81%)

class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        for i in range(len(A)):
            if i - A[i] > 1 or i - A[i] < -1: return False
        return True
