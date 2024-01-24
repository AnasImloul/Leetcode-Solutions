// Runtime: 81 ms (Top 100.0%) | Memory: 22.00 MB (Top 52.27%)

class Solution:
    def minimumScore(self, s: str, t: str) -> int:
        j = 0
        forward = [0]
        for c in s:
            if t[j] == c:
                j += 1
            if j >= len(t):
                return 0
            forward.append(j)
            
        j = len(t) - 1
        backward = [j]
        for c in reversed(s):
            if t[j] == c:
                j -= 1
            backward.append(j)
        return min(b - a for a, b in zip(forward, reversed(backward))) + 1              
