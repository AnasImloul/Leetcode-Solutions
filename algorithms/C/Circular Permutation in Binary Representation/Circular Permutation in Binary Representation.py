class Solution:
    def circularPermutation(self, n: int, s: int) -> List[int]:
        
        def findbin(n):
            if n==1:
                return [0,1]
            
            l=findbin(n-1)
            nl=[]
            for x in l:
                nl.append(x)
            mask=(1<<(n-1))
            for i in range(len(l)-1,-1,-1):
                nl.append(l[i]|mask)
            return nl
        
        l=findbin(n)
        index=0
        
        for i in range(len(l)):
            
            if l[i]==s:
                index=i
                break
        return l[i:]+l[:i]
    
            
