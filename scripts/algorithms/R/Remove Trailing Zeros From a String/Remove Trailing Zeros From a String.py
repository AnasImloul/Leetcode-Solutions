# Runtime: 49 ms (Top 63.5%) | Memory: 16.42 MB (Top 32.1%)

class Solution:
    def removeTrailingZeros(self, num: str) -> str:

        while(num[-1] == '0'):
            num = num[:-1]
        return num
        