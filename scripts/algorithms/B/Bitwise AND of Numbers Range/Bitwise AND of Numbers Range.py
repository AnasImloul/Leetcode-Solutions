// Runtime: 125 ms (Top 17.27%) | Memory: 13.9 MB (Top 25.09%)
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if not left: return 0
        i = 0
        cur = left
        while cur + (cur & -cur) <= right:
            cur += cur & -cur
            left &= cur
        return left