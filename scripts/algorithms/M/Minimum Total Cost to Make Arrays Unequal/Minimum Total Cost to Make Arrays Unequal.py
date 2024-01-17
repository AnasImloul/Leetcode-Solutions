// Runtime: 819 ms (Top 88.89%) | Memory: 41.00 MB (Top 14.29%)

class Solution:
    def minimumTotalCost(self, A, B):
        N = len(A)
        indexes = {i for i in range(N) if A[i] == B[i]}
        if not indexes:
            return 0

        count = Counter(A[i] for i in indexes)
        major = max(count, key=count.__getitem__)
        to_add = max(count[major] * 2 - len(indexes), 0)
        for i in range(N):
            if to_add and A[i] != major != B[i] and i not in indexes:
                to_add -= 1
                indexes.add(i)

        return -1 if to_add else sum(indexes)
