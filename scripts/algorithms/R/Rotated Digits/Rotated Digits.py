# Runtime: 226 ms (Top 14.46%) | Memory: 13.9 MB (Top 71.45%)
class Solution:
    def rotatedDigits(self, n: int) -> int:
        d={
            0:0,
            1:1,
            2:5,
            3:None,
            4: None,
            5:2,
            6:9,
            7:None,
            8:8,
            9:6
        }
        res=0
        for i in range(n+1):
            t=i
            pos=0
            temp=0
            status=True
            while t>0:
                r=d[t%10] #Every Digit Rotation Is Must, We Don't Have Choice To Leave It Without Rotating
                if r is None:
                    status=False
                    break

                temp+=((10**pos)*r)
                pos+=1
                t=t//10

            if temp!=i and status:
                res+=1
        return res