class Solution:
    def minInteger(self, num: str, k: int) -> str:
        n=len(num)
        ft=[0]*(n+1)
        D=defaultdict(lambda : deque())
        for idx,val in enumerate(num):
            D[int(val)].append(idx+1)
            
        def update(i,no):
            while i<=n:
                ft[i]+=no
                i += i & -i
                
        def query(i):
            res=0
            while i>0:
                res+=ft[i]
                i -= i & -i
            return res
        
        ans=""
        t=0
        while k>0:
            flag=False
            for i in range(10):
                if len(D[i])>0:
                    x=D[i][0]-query(D[i][0])-1
                    if k>=x:
                        k-=x
                        flag=True
                        ans+=str(i)
                        update(D[i][0],1)
                        D[i].popleft()
                        break
            if not flag:
                break
        temp=[]
        for key in D:
            for val in D[key]:
                temp.append((val,key))
        temp.sort()
        for idx,no in temp:
            ans+=str(no)
        return ans
        
                
        
