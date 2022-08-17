from collections import defaultdict
class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        first_occured_index = defaultdict(lambda:float('inf'),{0:-1})
        cur = res = 0
        for i, c in enumerate(s):
            if c in "aeiou":
                cur ^= (1<<(ord(c)-ord('a')))
                first_occured_index[cur] = min(first_occured_index[cur], i)
            res = max(res, i-first_occured_index[cur])
        return res