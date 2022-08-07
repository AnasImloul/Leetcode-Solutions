class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        s=num[0]
        q=["+","-","*",""]
        ans=[]
        def cal(w):
            i=1
            while i<len(w)-1:
                if w[i]=='*':
                    q=int(w[i-1])*int(w[i+1])
                    del w[i+1]
                    del w[i]
                    w[i-1]=q
                    continue
                i+=2
            i=1 
            while i<len(w)-1:
                if w[i]=='+':
                    q=int(w[i-1])+int(w[i+1])
                    del w[i+1]
                    del w[i]
                    w[i-1]=q
                    continue
                elif w[i]=='-':
                    q=int(w[i-1])-int(w[i+1])
                    del w[i+1]
                    del w[i]
                    w[i-1]=q
                    continue
                i+=2
            return w
        def dfs(s,i):
            nonlocal ans
            if i==len(num):
                x=''
                myl=[]
                for i in s:
                    if i not in ['+','-','*']:
                        x+=i
                    else:
                        myl.append(int(x))
                        myl.append(i)
                        x=''
                myl.append(int(x))
                print(myl)
                a=cal(myl)
                print(a)
                if a[0]==target:
                    ans.append(s)
                return
            for j in q:
                dfs(s+j+num[i],i+1)
        dfs(s,1)
        return ans
