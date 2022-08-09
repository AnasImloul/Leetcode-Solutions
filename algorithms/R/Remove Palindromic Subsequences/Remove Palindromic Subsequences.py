class Solution:
    def removePalindromeSub(self, s: str) -> int:
        convo=list(s)
        new=[]
        poli=[]
        count=[]
        ty=0
        for i in range(0,len(s)):
            c=''
            for j in range(i,len(s)):
                c+=s[j]
                new.append(c)
        for i in new:
            if i==i[::-1]:
                poli.append(i)
        for i in poli:
            count.append(len(i))
        c=poli[count.index(max(count))]
            #print(c)
        if c in s:
            ty+=1
        for i in c:
            if i in convo:
                convo.remove(i)
        if len(convo)==1:
                ty+=1
        if len(convo)>1:
            ty+=1
        return(ty)
