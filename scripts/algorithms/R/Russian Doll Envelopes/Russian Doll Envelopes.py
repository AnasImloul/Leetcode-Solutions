# Runtime: 1587 ms (Top 72.81%) | Memory: 61.7 MB (Top 65.15%)

from bisect import bisect_left
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes = sorted(envelopes, key= lambda x:(x[0],-x[1]))
        rst = []
        for _,h in envelopes:
            i = bisect_left(rst,h)
            if i == len(rst):
                rst.append(h)
            else:
                rst[i] = h
        return len(rst)