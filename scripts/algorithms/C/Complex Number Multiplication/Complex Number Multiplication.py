class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        i1=num1.index('+')
        i2=num2.index('+')
        a=int(num1[0:i1])
        x=int(num2[0:i2])
        b=int(num1[i1+1:len(num1)-1])
        y=int(num2[i2+1:len(num2)-1])
        ans1=a*x+(-1)*b*y
        ans2=a*y+b*x
        return str(ans1)+'+'+(str(ans2)+'i')