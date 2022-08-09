class Solution(object):
    def equalSubstring(self, s, t, maxCost):
        """
        :type s: str
        :type t: str
        :type maxCost: int
        :rtype: int
        """
        
        
        
        
        best = 0
        
        windowCost = 0
        l = 0
        for r in range(len(s)):
            
            windowCost += abs(ord(s[r]) - ord(t[r]))
            
            while windowCost > maxCost:
                
                windowCost -= abs(ord(s[l]) - ord(t[l]))
                l+=1
                
            best = max(best,r-l+1)
            
        return best
                
            
            

