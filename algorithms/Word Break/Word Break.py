from functools import cache
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @cache
        def dfs(i):
            if i == len(s): return True
            for word in wordDict:
                if s.startswith(word, i) and dfs(i+len(word)): return True
            return False
        return dfs(0)