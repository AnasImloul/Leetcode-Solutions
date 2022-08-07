class Solution:
    def findComplement(self, num: int) -> int:
        i = 0
        while(2**i <= num):
            i += 1
        return (2**i - num - 1)
