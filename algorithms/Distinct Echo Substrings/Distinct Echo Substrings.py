class Solution:
    def distinctEchoSubstrings(self, s: str) -> int:
        hash=set()
        n=len(s)
        for i in range(n):
            for j in range(i):
                
                if (i-j)&1==1:
                    
                    k=(i-j)//2
                    
                    if s[j:j+k+1]==s[j+k+1:i+1]:
                        hash.add(s[j:j+k+1]+s[j+k+1:i+1])
        return len(hash)
                    
                    
                    
        
