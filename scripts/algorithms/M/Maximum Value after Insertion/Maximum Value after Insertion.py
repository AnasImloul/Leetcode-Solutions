class Solution:
    def maxValue(self, n: str, x: int) -> str:
        if int(n)>0:
            ans = ""
            flag = False
            for i in range(len(n)):
                if int(n[i])>=x:
                    ans += n[i]
                else:
                    a = n[:i]
                    b = n[i:]
                    ans = a+str(x)+b
                
                    flag = True
                    break
            if not flag:
                ans += str(x)
        else:
            n = n[1:]
            ans = ""
            flag = False
            for i in range(len(n)):
                if int(n[i])<=x:
                    ans += n[i]
                else:
                    a = n[:i]
                    b = n[i:]
                    ans = a+str(x)+b
            
                    flag = True
                    break
            if not flag:
                ans += str(x)
            ans = "-"+ans
        
        return ans
                    
