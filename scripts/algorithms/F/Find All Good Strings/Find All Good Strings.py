from functools import lru_cache
class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        def srange(a, b):
            return [chr(i) for i in range(ord(a),ord(b)+1)]
        def LPS(pat):
            lps = [0]
            i, target = 1, 0
            while i < len(pat):
                if pat[i] == pat[target]:
                    target += 1
                    lps.append(target)
                    i += 1
                elif target:
                    target = lps[target-1]
                else:
                    lps.append(0)
                    i += 1
            return lps
        lps = LPS(evil)
        M = 10**9+7
        @lru_cache(None)
        def dfs(i, max_matched_idx, lb, rb):
            if max_matched_idx == len(evil): return 0
            if i == n: return 1
            l = s1[i] if lb else 'a'
            r = s2[i] if rb else 'z'
            candidates = srange(l, r)
            res = 0
            for j, c in enumerate(candidates):
                nxt_matched_idx = max_matched_idx
                while evil[nxt_matched_idx] != c and nxt_matched_idx:
                    nxt_matched_idx = lps[nxt_matched_idx-1]
                res = (res + dfs(i+1, nxt_matched_idx+(c==evil[nxt_matched_idx]),
                          lb = (lb and j == 0), rb = (rb and j==len(candidates)-1)))%M
            return res
        return dfs(0, 0, True, True)