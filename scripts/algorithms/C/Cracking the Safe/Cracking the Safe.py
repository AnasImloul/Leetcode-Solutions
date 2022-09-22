# Runtime: 121 ms (Top 27.97%) | Memory: 27.9 MB (Top 17.84%)
class Solution:
    def crackSafe(self, n: int, k: int) -> str:
        seen=set()
        def dfs(s,last_n):
            if len(seen)==(k**n): return s
            if len(last_n)<n: # If len<n,keep adding zeros as and valid string can be returned
                if len(s+"0")==n:
                    seen.add(s+"0")
                ans=dfs(s+"0",last_n+"0")
                return ans
            ans=None
            for i in range(k):
                new=last_n[1:]+str(i)
                if new not in seen:
                    seen.add(new)
                    ans=dfs(s+str(i),new)
                    if ans: return ans
                    seen.remove(new)
        return dfs("","")