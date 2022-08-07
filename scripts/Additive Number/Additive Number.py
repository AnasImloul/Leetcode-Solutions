class Solution:
def isAdditiveNumber(self, num: str) -> bool:
    
    def isadditive(num1,num2,st):
        if len(st) == 0:
            return True
        num3 = str(num1+num2)
        l = len(num3)
        return num3 == st[:l] and isadditive(num2,int(num3),st[l:])
    
    for i in range(1,len(num)-1):
        for j in range(i+1,len(num)):
            if num [0] == "0" and i != 1:
                break
            if num[i] == "0" and i+1 != j:
                break
           
            if isadditive(int(num[:i]),int(num[i:j]),num[j:]):
                
                return True
    return False
