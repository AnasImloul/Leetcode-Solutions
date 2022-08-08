from functools import lru_cache
from collections import Counter
class Solution(object):
    def minStickers(self, stickers, target):
        counter = [Counter(sticker) for sticker in stickers] 
        n = len(counter)
        @lru_cache(None)
        def dfs(target):
            if not target: return 0
            targ_counter = Counter(target)
            res = float('inf')
            #using sticker[i] if it contains the first letter of target
            for i in range(n):
                if counter[i][target[0]] == 0:
                    continue
                s = ''
                for j in 'abcdefghijklmnopqrstuvwxyz':
                    s += j*max(targ_counter[j] - counter[i][j], 0) 
                res = min(res, 1 + dfs(s)) if dfs(s) != -1 else res
            return -1 if res == float('inf') else res
        return dfs(target)