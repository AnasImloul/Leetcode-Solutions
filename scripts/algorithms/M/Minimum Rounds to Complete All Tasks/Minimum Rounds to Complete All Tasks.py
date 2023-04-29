class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        dic={}
        c=0
        for i in tasks:
            if i in dic.keys():
                dic[i]+=1
            else:
                dic[i]=1
        for i in dic.keys():
            if dic[i]==1:
                return -1
            while dic[i]>=2:
                if dic[i]-3>1:
                    dic[i]-=3
                    c+=1
                else:
                    dic[i]-=2
                    c+=1
        return c