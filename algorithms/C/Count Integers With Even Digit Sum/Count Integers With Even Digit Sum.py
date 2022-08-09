class Solution:
    def countEven(self, num: int) -> int:
        if num%2!=0:
            return (num//2)
        s=0
        t=num
        while t:
            s=s+(t%10)
            t=t//10
        if s%2==0:
            return num//2
        else:
            return (num//2)-1
