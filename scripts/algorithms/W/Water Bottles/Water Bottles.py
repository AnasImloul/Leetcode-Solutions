class Solution:
    def numWaterBottles(self, a: int, b: int) -> int:
        
        def sol(a,b,e,res):
            if a!=0: res += a
            if (a+e)<b: return res 
            a += e
            new=a//b
            e = a-(new*b)
            a=new
            return sol(a,b,e,res)
        
        return sol(a,b,0,0)
