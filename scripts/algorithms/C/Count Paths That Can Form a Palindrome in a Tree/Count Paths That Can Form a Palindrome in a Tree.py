# Runtime: 988 ms (Top 84.67%) | Memory: 72.40 MB (Top 67.15%)

class Solution:

    def dfs(self, x: int, mask: int, s: str, con: List[List[int]], have: Dict[int, int]) -> int:
        r: int = 0
        if x:
            mask ^= 1 << (ord(s[x]) - ord('a'))
            i: int = 1 << 25
            while i:
                if mask ^ i in have:
                    r += have[mask ^ i]
                i >>= 1
            r += have.get(mask, 0)
            have[mask] = have.get(mask, 0) + 1
        for y in con[x]:
            r += self.dfs(y, mask, s, con, have)
        return r

    def countPalindromePaths(self, parent: List[int], s: str) -> int:
        n: int = len(s)
        con: List[List[int]] = [[] for _ in range(n)]
        for i in range(1, n):
            con[parent[i]].append(i)
        have: Dict[int, int] = {0: 1}
        return self.dfs(0, 0, s, con, have)
