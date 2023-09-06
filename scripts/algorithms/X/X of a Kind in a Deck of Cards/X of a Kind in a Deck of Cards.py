# Runtime: 130 ms (Top 52.6%) | Memory: 16.56 MB (Top 64.6%)

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        
        
        f=defaultdict(int)
        
        for j in deck:
            f[j]+=1
           
        
        import math
        
        u=list(f.values())
        
        g=u[0]
        
        for j in range(1,len(u)):
            g=math.gcd(g,u[j])
        return g!=1
      
        