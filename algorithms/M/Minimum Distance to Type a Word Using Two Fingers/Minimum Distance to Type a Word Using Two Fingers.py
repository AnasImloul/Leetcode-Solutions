from functools import cache
class Solution:
    def minimumDistance(self, word: str) -> int:
        alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        COL = 6
        index = { c:(i//COL, i%COL) for i, c in enumerate(alphabets)}
        def dist(a, b):
            return abs(index[a][0] - index[b][0]) + abs(index[a][1] - index[b][1])
        @cache
        def dfs(lhand, rhand, i):
            if i == len(word): return 0
            res = float('inf')
            res = min(res, dfs(word[i], rhand, i+1)) if lhand == -1 else min(res, dist(lhand, word[i])+dfs(word[i], rhand, i+1))
            res = min(res, dfs(lhand, word[i],i+1)) if rhand == -1 else min(res, dist(word[i], rhand) + dfs(lhand, word[i], i+1))
            return res
        return dfs(-1, -1, 0)