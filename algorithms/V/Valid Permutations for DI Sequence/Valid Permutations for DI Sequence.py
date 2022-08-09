class Solution:
    def recursion(self,idx,s,prev,limit,val,used):
        if idx == limit + 1:
            return 1
        if (idx,prev) in self.dp:return self.dp[(idx,prev)]
        start = 0 if s[idx-1] == 'D' else prev + 1
        end = prev -1 if s[idx-1] == 'D' else limit
        ans = 0
        for i in range(start,end+1):
            if i in used and used[i]==True:continue
            used[i] = True
            ans+=self.recursion(idx+1,s,i,limit,val+str(i),used)
            used[i] = False
        self.dp[(idx,prev)]=ans
        return ans
    def numPermsDISequence(self, s: str) -> int:
        limit = len(s)
        ans = 0
        self.dp = {}
        for i in range(limit+1):
            ans+= self.recursion(1,s,i,limit,str(i),{i:True})
        return ans%1000000007
