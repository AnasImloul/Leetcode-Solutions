class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        c=0
        res=''
        for i in s:
            if i==')' and c==1:
                c=c-1
            elif i=='(' and c==0:
                c=c+1
            elif i=='(':
                res=res+'('
                c=c+1
            elif i==')':
                res=res+')'
                c=c-1
        return res
