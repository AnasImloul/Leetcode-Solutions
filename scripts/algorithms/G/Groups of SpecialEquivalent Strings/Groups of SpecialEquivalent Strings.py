# Runtime: 41 ms (Top 96.5%) | Memory: 16.56 MB (Top 88.1%)

class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        res = set()
        for s in A:
            sort_odd_even = ''.join(sorted(s[1::2]) + sorted(s[::2]))
            res.add(sort_odd_even)
        return len(res)