# Runtime: 40 ms (Top 58.1%) | Memory: 16.21 MB (Top 73.9%)

class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        x=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        a=""
        for i in firstWord:
            a=a+str(x.index(i))
        
        b=""
        for i in secondWord:
            b=b+str(x.index(i))

        c=""
        for i in targetWord:
            c=c+str(x.index(i))
        if int(a)+int(b)==int(c):
            return True
        return False