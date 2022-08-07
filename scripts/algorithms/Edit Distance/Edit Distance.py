from functools import cache


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        
        @cache
        def dp(i, j):
            if i == 0:
                return j
            if j == 0:
                return i
            
            l1, l2 = word1[i - 1], word2[j - 1]
            if l1 != l2:
                return 1 + min(
                    dp(i, j - 1),     # Delete / insert j
                    dp(i - 1, j),     # Delete / insert i
                    dp(i - 1, j - 1)  # Replace i or j
                )
            return dp(i - 1, j - 1)         
                    
        return dp(m, n)
