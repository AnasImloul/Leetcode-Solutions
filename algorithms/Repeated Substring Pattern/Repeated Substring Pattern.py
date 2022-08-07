class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:      
        i=0
        ans=""
        l=len(s)
        while i <l:
            ans+=s[i]
            if l%(i+1)==0:
                if ans*(l//(i+1)) == s:
                    if i==l-1:
                        return False
                    return True
            i+=1
        return False
