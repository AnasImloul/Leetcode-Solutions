// Runtime: 46 ms (Top 62.5%) | Memory: 16.50 MB (Top 18.75%)

class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
    
        end, n  = len(s)-1, s.count("0")    
        while end >=0 and  int(s[end:], 2)<= k:
            end-=1
        return n+ s[end+1:].count("1")
        
