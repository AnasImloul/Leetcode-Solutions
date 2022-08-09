class Solution(object):
    def letterCasePermutation(self, s):
        
        if s=="":
            return [""]
        t=s[0].lower()
        li=[]
        res=self.letterCasePermutation(s[1:])
        for i in res:
            li.append(t+i)
        if t not in "1234567890":
            for i in res:
                li.append(t.upper()+i)
        return li
            
           
        
