// Runtime: 209 ms (Top 60.0%) | Memory: 21.90 MB (Top 65.0%)

class Solution:
    def maxHappyGroups(self, B, groups):
        ans = sum(g%B == 0 for g in groups)
        groups = [g for g in groups if g%B != 0]

        pos = [0]*B
        for g in groups: pos[g%B] += 1

        for i in range(1, B):
            t = min(pos[i], pos[B-i]) if 2*i != B else pos[i]//2
            ans += t
            pos[i] -= t
            pos[B-i] -= t
            
        if sum(pos) == 0: return ans

        @lru_cache(None)
        def dfs(position, last):
            if sum(position) == 0: return 0

            ans = float("-inf")
            for i in range(B):
                if position[i] > 0:
                    t = [j for j in position]
                    t[i] -= 1
                    U = (last - i) % B
                    ans = max(ans, dfs(tuple(t), U) + (U == 0))
                      
            return ans

        return max(dfs(tuple(pos), i) for i in range(1, B)) + ans
