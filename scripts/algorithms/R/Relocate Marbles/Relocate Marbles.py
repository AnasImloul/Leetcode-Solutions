// Runtime: 634 ms (Top 94.74%) | Memory: 38.80 MB (Top 49.71%)

class Solution:
    def relocateMarbles(self, nums: List[int], moveFrom: List[int], moveTo: List[int]) -> List[int]:
        s = set(nums)
        for f, t in zip(moveFrom, moveTo):
            s.remove(f)
            s.add(t)
        return sorted(s)
