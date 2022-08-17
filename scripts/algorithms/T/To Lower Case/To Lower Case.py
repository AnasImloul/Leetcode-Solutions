#approach -1
class Solution:
    def toLowerCase(self, s: str) -> str:
        ch = ""
        for i in s:
            asc = ord(i)
            if asc > 64 and asc < 91:
                ch += chr(asc+32)
            else:
                ch +=chr(asc)
        return ch
    
#approach -2
class Solution:
    return s.lower()
