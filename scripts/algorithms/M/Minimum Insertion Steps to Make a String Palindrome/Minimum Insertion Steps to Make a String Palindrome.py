class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        prev_prev = [0]*n
        prev = [0]*n
        curr = [0] * n

        for l in range(1, n):
            for i in range(l, n):
                if s[i] == s[i-l]:
                    curr[i] = prev_prev[i-1]
                else:
                    curr[i] = min(prev[i-1], prev[i])+1
            # print(curr)
            prev_prev, prev, curr = prev, curr, prev_prev
        
        return prev[-1]