# Runtime: 5 ms (Top 40.00%) | Memory: 19.20 MB (Top 34.29%)

class Solution:
    def areSimilar(self, mat: List[List[int]], k: int) -> bool:

        deq = map(deque, mat)

        for i, row in enumerate(deq):

            shifted = row.copy()
            shifted.rotate(k)

            if row != shifted: return False

        return True
