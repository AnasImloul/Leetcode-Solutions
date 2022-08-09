class Solution:
    def minDays(self, bd: List[int], m: int, k: int) -> int:
        
        
        def check(d):
            
            cont = 0
            anss =0
            for i in bd:
                
                if i<=d:
                    cont+=1
                else:
                    anss += cont//k
                    cont=0
            
            anss += cont//k
            return anss >=m
        
        l,r = 1, max(bd)
        ans = -1
        
        while l<=r:
            
            mid = (l+r)//2
            
            if check(mid):
                
                ans = mid
                r = mid-1
            else:
                l = mid+1
                
        return ans
        
        
        
        
