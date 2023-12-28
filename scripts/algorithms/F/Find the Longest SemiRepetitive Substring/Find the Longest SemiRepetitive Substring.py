// Runtime: 59 ms (Top 96.65%) | Memory: 17.40 MB (Top 8.38%)

class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:

                                                                #    s = '52233'
        s = s[0] + s + s[-1]                                    #    s = '5522333'

        arr = [i for i in range(len(s)-1) if s[i] == s[i+1]]    #  ans = [0, 2, 4, 5]
        
        return max ((y - x for x,y in zip(arr, arr[2:])),       # return max(4-0, 5-2) = 4
                                         default = len(s)-2)
