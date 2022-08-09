class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        ans, n = 0, len(s)
        def dfs(i, cnt, visited):
            nonlocal ans, n
            if i == n: ans = max(ans, cnt); return  # stop condition
            for j in range(i+1, n+1):    
                if s[i:j] in visited: continue      # avoid re-visit/duplicates
                visited.add(s[i:j])                 # update visited set
                dfs(j, cnt+1, visited)              # backtracking
                visited.remove(s[i:j])              # recover visited set for next possibility
        dfs(0, 0, set())                            # function call
        return ans
