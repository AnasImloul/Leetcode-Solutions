# Runtime: 135 ms (Top 57.32%) | Memory: 18.2 MB (Top 23.17%)
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        ans = []
        letters = ['a','b','c']
        def happystr(n,prev,temp):
            if n==0:
                ans.append("".join(temp))
                return
            for l in letters:
                if l!=prev:
                    happystr(n-1,l,temp+[l])
        happystr(n,"",[])
        if len(ans)<k:
            return ""
        return ans[k-1]
