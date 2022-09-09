# Runtime: 271 ms (Top 15.83%) | Memory: 15.4 MB (Top 41.73%)
class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def pal(x):
            return x == x[::-1]
        if pal(a) or pal(b): return True
        # either grow from inside to outside, or vice versa
        ina = len(a)-1
        inb = 0
        outa = 0
        outb = len(b)-1

        while a[ina] == b[inb]:
            ina -= 1
            inb += 1
            if ina <= inb:
                return True # short circuit found break point
        # jump into each string now!?
        # is a or b a palindrome in this portion from inb to ina
        if pal(a[inb:ina+1]) or pal(b[inb:ina+1]):
            return True # either one is breakpoint, so check remainder is palindrome

        while a[outa] == b[outb]:
            outa += 1
            outb -= 1
            if outa >= outb:
                return True
        if pal(a[outa:outb+1]) or pal(b[outa:outb+1]):
            return True # either one is breakpoint, so check remainder

        return False