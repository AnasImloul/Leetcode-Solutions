# Runtime: 2209 ms (Top 51.91%) | Memory: 30.3 MB (Top 21.37%)
class Solution:
    def getXORSum(self, arr1: List[int], arr2: List[int]) -> int:
        def xor_lis(lis): return functools.reduce(lambda a,b : a^b,lis)
        return xor_lis(arr1) & xor_lis(arr2)