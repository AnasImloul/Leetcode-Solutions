class Solution:
    def interchangeableRectangles(self, rectangles: List[List[int]]) -> int:
        ratios = defaultdict(int)
        for x, y in rectangles:
            ratios[x/y] += 1
        res = 0
        for val in ratios.values():
            res += (val*(val-1)//2)
        return res
