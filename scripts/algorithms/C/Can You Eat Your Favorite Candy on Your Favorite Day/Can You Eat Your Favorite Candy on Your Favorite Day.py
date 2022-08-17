class Solution:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        A = list(accumulate(candiesCount))
        res = []
        for type, day, cap in queries:
            if type == 0:
                res.append(A[0] > day)
            else:
                to_be_eaten = A[type-1] + 1
                res.append(to_be_eaten <= ((day + 1) * cap) and A[type] > day)
        return res
