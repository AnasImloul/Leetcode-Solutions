mod=1000000007
@cache
def func(n,prev,pp):
    if n==0:
        return 1
    ans=0
    for i in range(1,7):
        if prev==-1:
            ans+=func(n-1,i,prev)
            ans=ans%mod
        elif pp==-1:
            if(math.gcd(i,prev)==1 and i!=prev):
                ans+=func(n-1,i,prev)
                ans=ans%mod
        else:
            if(math.gcd(i,prev)==1 and i!=prev and i!=pp):
                ans+=func(n-1,i,prev)
                ans=ans%mod
    return ans;
class Solution:
    
            
    def distinctSequences(self, n: int) -> int:
        return func(n,-1,-1)
