from collections import defaultdict

class Solution:
    def reachingPoints(self, sx: int, sy: int, tx: int, ty: int) -> bool:
        def nextNum(ta,tb,s):
            if ta % tb == s % tb:
                return min(ta, s)
            return ta % tb
        visited = defaultdict(bool)
        while tx >= sx and ty >= sy and (sx != tx or sy != ty):
            if tx > ty:
                tx, ty = nextNum(tx, ty, sx), ty
            else:
                tx, ty = tx, nextNum(ty, tx, sy)
            if visited[(tx,ty)]:
                break
            visited[(tx,ty)] = True
        return (sx == tx) and (sy == ty)
