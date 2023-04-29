class Solution:
    def minBitFlips(self, s: int, g: int) -> int:
        count = 0 
        while s or g:
            if s%2 != g%2: count+=1
            s, g = s//2, g//2
        return count