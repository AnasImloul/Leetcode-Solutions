class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        i=0
        d={}
        for j in key:
            if j!=" " and j not in d:
                d[j]=alpha[i]
                i+=1
            if len(d)==26:
                break
        res=""
        d[" "]=" "
        for i in message:
            res+=d[i]
        return res
