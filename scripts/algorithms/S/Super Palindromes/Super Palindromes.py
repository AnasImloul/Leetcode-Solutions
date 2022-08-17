class Solution:
    def superpalindromesInRange(self, left: str, right: str) -> int:
        ans = 1 if 9 >= int(left) and 9 <= int(right) else 0
        
        def isPal(s: str) -> bool:
            return s == s[::-1]
        
        for dig in range(1, 10):
            isOdd = dig % 2 and dig != 1
            innerLen = (dig >> 1) - 1
            innerLim = max(1, 2 ** innerLen)
            midPos = dig >> 1
            midLim = 3 if isOdd else 1
            for edge in range (1, 3):
                pal = [0] * dig
                pal[0], pal[-1] = edge, edge
                if edge == 2: innerLim, midLim = 1, min(midLim, 2)
                for inner in range(innerLim):
                    if inner > 0:
                        innerStr = list(bin(inner)[2:].zfill(innerLen))
                        pal[1:1+innerLen] = innerStr
                        pal[-innerLen-1:-1] = reversed(innerStr)
                    for mid in range(midLim):
                        if isOdd: pal[midPos] = mid
                        palin = int("".join([str(n) for n in pal]))
                        square = palin * palin
                        if square > int(right): return ans
                        if square >= int(left) and isPal(str(square)): ans += 1
        return ans
