class Solution:
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        psum, next, prev = [0] * (len(s) + 1), [inf] * (len(s) + 1), [0] * (len(s) + 1)
        res = []
        for i, ch in enumerate(s):
            psum[i + 1] = psum[i] + (ch == '|')
            prev[i + 1] = i if ch == '|' else prev[i]
        for i, ch in reversed(list(enumerate(s))):
            next[i] = i if ch == '|' else next[i + 1]
        for q in queries:
            l, r = next[q[0]], prev[q[1] + 1]
            res.append(r - l - (psum[r] - psum[l]) if l < r else 0)
        return res
