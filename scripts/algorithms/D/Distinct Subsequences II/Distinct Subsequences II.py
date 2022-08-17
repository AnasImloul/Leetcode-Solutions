class Solution:
    def distinctSubseqII(self, s: str) -> int:
        #number of subsequences that startwith each alphabet
        startwith = [0]*26
        for c in s[::-1]:
            startwith[ord(c)-ord('a')] = sum(startwith) + 1
        return sum(startwith)%(10**9+7)
