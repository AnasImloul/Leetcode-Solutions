class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        def lcs(ind1,ind2):
            prev=[0 for i in range(ind2+1)]
            curr=[0 for i in range(ind2+1)]
            
            for i in range(1,ind1+1):
                for j in range(1,ind2+1):
                    if text1[i-1]==text2[j-1]:
                        curr[j]=1+prev[j-1]
                         
                    else:
                        curr[j]=max(prev[j],curr[j-1])
                prev=list(curr) # remember to use a new list for prev

            return prev[-1]
                    
        
        ans=lcs(len(text1),len(text2))
        return ans
