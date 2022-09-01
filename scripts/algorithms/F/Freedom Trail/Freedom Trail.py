# Runtime: 121 ms (Top 97.21%) | Memory: 14.1 MB (Top 67.25%)
class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        char_pos = defaultdict(set)
        for i, c in enumerate(ring):
            char_pos[c].add(i)

        def minStep(fromm, to):
            if fromm == to:
                return 0
            minSteps = abs(fromm - to)
            minSteps = min(minSteps, abs(len(ring) - minSteps))
            return minSteps

        n = len(key)
        dp = [0] * len(ring)
        for p in char_pos[key[0]]:
            dp[p] = minStep(0, p)
        prev_char = key[0]
        for c in key[1:]:
            if prev_char == c:
                continue
            for next_pos in char_pos[c]:
                dp[next_pos] = min(dp[prev_pos] + minStep(prev_pos, next_pos) for prev_pos in char_pos[prev_char])
            prev_char = c
        return min(dp[p] for p in char_pos[prev_char]) + len(key)