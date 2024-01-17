// Runtime: 42 ms (Top 82.55%) | Memory: 17.30 MB (Top 56.7%)

from math import ceil
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        single_ele = 2**(n-1)
        if k>3*single_ele:
            return ""
        result = ['a','b','c'][ceil(k/single_ele)-1]
        while single_ele>1:
            k = (k-1)%single_ele +1
            single_ele = single_ele//2
            if result[-1]=='a':
                result+=['b','c'][ceil(k/single_ele)-1]
            elif result[-1]=='b':
                result+=['a','c'][ceil(k/single_ele)-1]
            else:
                result+=['a','b'][ceil(k/single_ele)-1]
        return result
