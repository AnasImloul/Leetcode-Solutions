# Runtime: 1384 ms (Top 56.07%) | Memory: 30.3 MB (Top 20.56%)
class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        def xor_lis(lis): return functools.reduce(lambda a,b : a^b,lis)
        return xor_lis(arr1) & xor_lis(arr2)