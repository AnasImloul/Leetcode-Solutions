// Runtime: 1795 ms (Top 74.72%) | Memory: 380.50 MB (Top 27.21%)

class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10 ** 9 + 7
        m, n = len(words[0]), len(target)
        charAtIndexCnt = [[0] * m for _ in range(128)]
        for word in words:
            for i, c in enumerate(word):
                charAtIndexCnt[ord(c)][i] += 1  # Count the number of character `c` at index `i` of all words

        @lru_cache(None)
        def dp(k, i):
            if i == n:  # Formed a valid target
                return 1
            if k == m:  # Reached to length of words[x] but don't found any result
                return 0
            c = target[i]
            ans = dp(k + 1, i)  # Skip k_th index of words
            if charAtIndexCnt[ord(c)][k] > 0: # Take k_th index of words if found character `c` at index k_th
                ans += dp(k + 1, i + 1) * charAtIndexCnt[ord(c)][k]
                ans %= MOD
            return ans

        return dp(0, 0)
