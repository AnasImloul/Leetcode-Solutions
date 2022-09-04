# Runtime: 86 ms (Top 48.63%) | Memory: 14 MB (Top 27.24%)
class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        def segment(ax1,ax2,bx1,bx2):
            return min(ax2,bx2) - max(ax1, bx1) if max(ax1, bx1) < min(ax2, bx2) else 0
        return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - segment(ax1,ax2,bx1,bx2)*segment(ay1,ay2,by1,by2)