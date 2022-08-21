# Runtime: 62 ms (Top 13.03%) | Memory: 13.8 MB (Top 53.14%)

class Solution:
    def findComplement(self, num: int) -> int:
        i = 0
        while(2**i <= num):
            i += 1
        return (2**i - num - 1)