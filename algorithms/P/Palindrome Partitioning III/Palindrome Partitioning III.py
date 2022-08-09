class Solution:
    def palindromePartition(self, s: str, t: int) -> int:
        n=len(s)
        @lru_cache(None)
        def is_palin(s):                #This function returns min no of chars to change to make s as a palindrome
            cnt=0
            for c1,c2 in zip(s,s[::-1]):
                if c1!=c2: cnt+=1
            if len(s)%2==0:
                return cnt//2
            return (cnt+1)//2
        @lru_cache(None)
        def dp(i,j,k):            #We analyse string s[i:j+1] with k divisions left
            if j==n:
                return 0 if k==0 else sys.maxsize
            if k==0: 
                return sys.maxsize
            ans=sys.maxsize
            cnt=is_palin(s[i:j+1])
            #terminate here
            ans=min(ans,dp(j+1,j+1,k-1)+cnt)
            #dont terminate
            ans=min(ans,dp(i,j+1,k))
            return ans
        return dp(0,0,t)
                        
                
            
