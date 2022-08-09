class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        cmp=strs[0]
        for i in range(1,len(strs)):
            l=0
            if (len(cmp)>len(strs[i])):
                l+=len(strs[i])
            else:
                l+=len(cmp)
            ans=""
            for j in range(l):
                if (cmp[j]!=strs[i][j]):
                    if (j==0):
                        return ""
                    else:
                        break
                else:
                    ans+=strs[i][j]
            cmp=ans
        return cmp
		
Upvote If you Like!!!