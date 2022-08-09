class Solution:
    def thousandSeparator(self, n: int) -> str:
        n=str(n)
        l=len(n)
        if l<=3:
            return n
        ans=""
        for i in range(-1,-(l+1),-1):
            #print(i,n[i])
            if (i%3==0) :
                ans+=n[i]
                ans+="."
            else:
                ans+=n[i]
        ans=ans[::-1]
        if ans[0]==".":
            return ans[1:]
        elif ans[-1] == ".":
            return ans[:-1]
        return ans
