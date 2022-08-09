class Solution:
    def tribonacci(self, n: int, q={}) -> int:
        if n<3:
            q[0]=0 #Initialize first 3 values 
            q[1]=1
            q[2]=1
        if n not in q:  #Have faith that last 3 calls will give the answer :)
            q[n]=self.tribonacci(n-1,q)+self.tribonacci(n-2,q)+self.tribonacci(n-3,q)
        return q[n]
