from collections import defaultdict
class Solution:
    def longestAwesome(self, s: str) -> int:
        mask = 0
        index = defaultdict(lambda:float('-inf'),{0:-1})
        res = 0
        for i,c in enumerate(s):
            mask ^= (1<<(ord(c)-ord('0')))
            if index[mask] == float('-inf'):
                index[mask] = i
            res = max(res, i-index[mask])
			#when the palindrome has one odd numbers of digits
            for j in range(10):
                tmp_mask = mask^(1<<j)
                res = max(res, i-index[tmp_mask] if index[tmp_mask] != float('-inf') else 0)
        return res