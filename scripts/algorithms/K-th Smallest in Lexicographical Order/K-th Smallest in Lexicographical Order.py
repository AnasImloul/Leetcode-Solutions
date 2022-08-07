class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        
        def prefix(op,n):
            if op==n: return 1
            if int(op)>int(n): return 0
            for i in range(len(op)):
                if int(op[i])>int(n[i]): 
                    rem = len(n)-1-len(op)
                    if not rem: return 1
                    return 1+int(10*((1-10**rem)/-9))
                elif int(op[i])<int(n[i]): 
                    rem = len(n)-len(op)
                    if not rem: return 1
                    return 1+int(10*((1-10**rem)/-9))
                
            res = 1
            for i in range(10):
                res += prefix(op+str(i),n)
            return res
    
        ans = 1
        while k>1:
            pref = prefix(str(ans),str(n)) 
            if pref >= k:
                ans*=10; k-=1
            else: 
                ans += 1; k-= pref
        
        return ans
    
    
