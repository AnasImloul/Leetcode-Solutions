class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
    
        end, n  = len(s)-1, s.count("0")    
        while end >=0 and  int(s[end:], 2)<= k:
            end-=1
        return n+ s[end+1:].count("1")
        
