class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        a, b, c = [],[],[]
        a_,b_,c_="","",""
        base = ord("a")
        
        def getList(l,s):
            for i in s:
                l.append(ord(i)-base)
            return l
        
        def getString(x,l):
            for i in l:
                x += str(i)
            return x
        
        a = getList(a,firstWord)
        b = getList(b,secondWord)
        c = getList(c,targetWord)
        
        a_ = getString(a_,a)
        b_ = getString(b_,b)
        c_ = getString(c_,c)
        
        return(( int(a_)+int(b_)) == int(c_))
