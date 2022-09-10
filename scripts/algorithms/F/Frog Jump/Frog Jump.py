# Runtime: 231 ms (Top 72.60%) | Memory: 19.2 MB (Top 61.18%)
class Solution:
    def possible(self, i, n, stones, pos, allowedJumps):
        if i == n - 1:
            return True
        key = tuple([i] + allowedJumps)
        if key in self.cache:
            return self.cache[key]
        for jump in allowedJumps:
            if jump > 0 and stones[i] + jump in pos:
                if self.possible(pos[stones[i] + jump], n, stones, pos, [jump - 1, jump, jump + 1]):
                    self.cache[key] = True
                    return True
        self.cache[key] = False
        return False

    def canCross(self, stones: List[int]) -> bool:
        n = len(stones)
        pos = {}
        for i, stone in enumerate(stones):
            pos[stone] = i
        self.cache = {}
        return self.possible(0, n, stones, pos, [1])