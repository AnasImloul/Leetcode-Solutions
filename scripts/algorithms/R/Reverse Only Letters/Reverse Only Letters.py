class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        l = []
        for i in s:
            if i.isalpha(): l.append(i)
                
        l = l[::-1]
        
        for i, c in enumerate(s):
            if c.isalpha() == False:
                l.insert(i, c)
                
        return "".join(l)