# Runtime: 47 ms (Top 65.12%) | Memory: 13.9 MB (Top 66.60%)
class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        s1 = s.split('0')
        s0 = s.split('1')
        r1 = max([len(i) for i in s1])
        r0 = max([len(i) for i in s0])
        return r1>r0