class Solution:
    def reverseVowels(self, s: str) -> str:
        s=list(s)
        vow=[]
        for i,val in enumerate(s):
            if val in ('a','e','i','o','u','A','E','I','O','U'):
                vow.append(val)
                s[i]='_'
                
        vow=vow[::-1]
        c=0
        print(vow)
        for i,val in enumerate(s):
            if val =='_':
                s[i]=vow[c]
                c+=1
        return "".join(s)
