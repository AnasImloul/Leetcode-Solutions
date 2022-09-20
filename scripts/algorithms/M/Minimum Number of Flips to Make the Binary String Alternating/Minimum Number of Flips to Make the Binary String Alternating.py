# Runtime: 631 ms (Top 87.94%) | Memory: 14.8 MB (Top 94.52%)
class Solution:
    def minFlips(self, s: str) -> int:
        prev = 0
        start_1, start_0, start_1_odd, start_0_odd = 0,0,sys.maxsize,sys.maxsize
        odd = len(s)%2
        for val in s:
            val = int(val)
            if val == prev:
                if odd:
                    start_0_odd = min(start_0_odd, start_1)
                    start_1_odd += 1
                start_1 += 1
            else:
                if odd:
                    start_1_odd = min(start_1_odd, start_0)
                    start_0_odd += 1
                start_0 += 1
            prev = 1 - prev
        return min([start_1, start_0, start_1_odd, start_0_odd])