class Solution:
    def findIntegers(self, n: int) -> int:
        b=(bin(n).replace("0b",""))
        dp=[[[[-1 for i in range(2)] for i in range(2)] for i in range(2)] for i in range(30)]
        def fun(i,last,tight,leading_zeros):
            if i==len(str(b)):
                return 1
            if dp[i][tight][leading_zeros][last]!=-1:
                return dp[i][tight][leading_zeros][last]
            end=1
            if tight==1:
                end = int(b[i])
            res=0
            for j in range(end+1):
                if j==0 and leading_zeros==1:
                    res+=fun(i+1,j,tight&int(j==end),1)
                else:
                    if j==0:
                        res+=fun(i+1,j,tight&int(j==end),0)
                    else:
                        if last!=j:
                            res+=fun(i+1,j,tight&int(j==end),0)
            dp[i][tight][leading_zeros][last] = res
            return res
        return fun(0,0,1,1)