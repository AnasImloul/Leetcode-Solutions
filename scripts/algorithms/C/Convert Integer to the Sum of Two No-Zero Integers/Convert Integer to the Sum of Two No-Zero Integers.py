class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        for i in range(1,n//2+1):
            first = str(i)
            second = str(n-i)
            if "0" not in first and "0" not in second:
                return [i, n-i]
