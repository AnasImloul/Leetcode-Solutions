
class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        
       
        
        
        ans = 0
        
        shist = {}
		thist = {}
		
        for i in range(len(s)):
            shist[s[i]] = shist.get(s[i],0)+1
			thist[t[i]] = thist.get(t[i],0)+1


            
            
                    
            
        ans = 0
        for ch in shist:
            
            if ch in thist:
                if shist[ch] - thist[ch] >0:
                    ans+= shist[ch] - thist[ch]
            else:
                ans+= shist[ch]
                
        return ans

