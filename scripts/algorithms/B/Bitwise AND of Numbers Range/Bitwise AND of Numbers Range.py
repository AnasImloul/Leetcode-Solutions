class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if not left: return 0
        i = 0
        cur = left
        while cur + (cur & -cur) <= right:
            cur += cur & -cur
            left &= cur
        return left