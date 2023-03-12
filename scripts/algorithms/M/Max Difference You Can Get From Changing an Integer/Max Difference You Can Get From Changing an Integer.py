class Solution:
    def maxDiff(self, num: int) -> int:
        i=0
        while i<len(str(num)):
            change = (str(num)[i])
            if change!='9':
                break
            i+=1
        
        i=0
        flag = False
        while i<len(str(num)):
            sc = (str(num)[i])
            if sc!='1' and sc!='0':
                if i>0:
                    flag =True
                break
            i+=1
        small = str(num)
        num = str(num)
        m=''
        for i in range(len(str(num))):
            if num[i]==change:
                m+='9'
            else:
                m+=num[i]
        m = int(m)
        s =''
        for i in range(len(num)):
            if small[i]==sc:
                if flag:
                    s+='0'
                else:
                    if small[i]=="0":
                        s+='0'
                    else:
                        s+='1'
            else:
                s+=small[i]
        small = int(s)
        return m - small