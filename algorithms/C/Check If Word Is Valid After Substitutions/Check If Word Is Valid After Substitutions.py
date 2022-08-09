class Solution:
    def isValid(self, s: str) -> bool:
        
        
        ans = ''
        for i in s:
            ans+=i
            while len(ans)>=3:
                if ans[-3:]=="abc":
                    ans=ans[0:-3]
                else:
                    break
            
        if ans=='':
            return True
        else:
            return False