class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        
        
        t=[0]*(60)
        
        for i in ranges:
            
            t[i[0]]+=1
            t[i[1]+1]-=1
            
        for i in range(1,len(t)):
            t[i] += t[i-1]
            
        return min(t[left:right+1])>=1
        
        
        
        
        
