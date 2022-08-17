class Solution:
    def minimumPerimeter(self, nap: int) -> int:
        
        
#         here for n = 2 , there are two series :  
#         (1) Diagnal points for n=3 , diagnal apples = 2*n = 6
#         (2) there is series =   2,3,3 =  2+ (sigma(3)-sigma(2))*2
        
#         how to solve:
            
#             here 3  =  sigma(n+(n-1))-sigma(n) = sigma(2*n-1)-sigma(n) =  0.5*2n*(2n-1)-0.5*n*n-1
#         (3) so our final 2,3,3 =   3*2+2 =   (0.5*2n*(2n-1)-0.5*n*n-1)*2+n
#         (4) so final 2,3,3 =  3*n*n - 2*n
#         (5) we have 4 times repitation of (2,3,3)  = 4*(2,3,3)  =   4*(3*n*n - 2*n)   =  12*n*n - 8*n
#         (6) we have 4 diagnal points so their sum(4 diagnal)  = 4*(2*n)
#         (7)  so final sum(total) = 4 diagnal sum + 4(2,3,3)    =   4(2*n)   + 12*n*n - 8*n    =  12*n*n
        
#         so at nth distance we have total  12*n*n  apples at the circumfrance
        
#         so net sum =  sigma(12*n*n)  = 2*n*(n+1)*(2*n+1)
        
        
        n=1
        val=2*n*(n+1)*(2*n+1)
        while(val<nap):
            n+=1
            val=val=2*n*(n+1)*(2*n+1)
        return n*8
