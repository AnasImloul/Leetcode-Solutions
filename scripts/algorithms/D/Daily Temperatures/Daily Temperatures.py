// Runtime: 1085 ms (Top 46.04%) | Memory: 30.40 MB (Top 85.02%)

class Solution:
    def dailyTemperatures(self, T):
        ans, s = [0]*len(T), deque()
        for cur, cur_tmp in enumerate(T):
            while s and cur_tmp > T[s[-1]]:
                ans[s[-1]] = cur - s[-1]
                s.pop()
            s.append(cur)
        return ans
