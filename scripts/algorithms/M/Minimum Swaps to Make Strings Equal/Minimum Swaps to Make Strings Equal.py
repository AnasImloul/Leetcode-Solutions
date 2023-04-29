class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        h = defaultdict(int)
        count = 0    # variable to keep track of the number of mismatches; it is impossible to make strings equal if count is odd
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                count += 1
                h[s1[i]] += 1
        if count % 2 != 0:     
            return -1
        res, a, b = 0, h['x'], h['y']
        res += a // 2 + b // 2
        if a % 2 == 0:
            return res
        return res + 2