from itertools import groupby

class Solution:
    def numSub(self, s: str) -> int:
        # strategy "run length encode" the input (only keep 1s)
        # based on the runs calculate total w/ n*(n+1)/2 sum trick
        # return modulo as specified
        one_counts = [len(list(l)) for k, l in groupby(s) if k == "1"]
        total = sum([c*(c+1)//2 for c in one_counts])
        return total % (10**9 + 7)       
