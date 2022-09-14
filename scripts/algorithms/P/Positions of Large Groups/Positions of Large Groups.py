# Runtime: 81 ms (Top 17.97%) | Memory: 13.9 MB (Top 73.17%)
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:

        i=0
        c=1
        prev=""
        l=len(s)
        ans=[]
        while i<l:
            if s[i]==prev:
                c+=1
                if (i==l-1) & (c>=3):
                    ans.append([i+1-c,i])
            else:
                if c>=3:
                    ans.append([i-c,i-1])
                c=1
            prev=s[i]
            i+=1
        return ans
