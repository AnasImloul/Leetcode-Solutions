class Solution:
    def recursion(self, digits , inc , size , n  , pos):
        ans = 0
        if pos == size:return 0
        if pos in self.dp:return self.dp[pos]
        for i in digits:
            if i < n[pos]:
                val = 1
                for j in range(size-pos):
                    ans+=val
                    val*=inc
            elif i > n[pos]:
                if size == pos + 1:continue
                val = 1
                for j in range(size-pos-1):
                    ans+=val
                    val*=inc
            else:
                ans+=1
                ans+=self.recursion(digits , inc , size , n ,pos+1)
        self.dp[pos]=ans
        return ans
    def atMostNGivenDigitSet(self, digits: List[str], n: int) -> int:
        n = str(n)
        self.dp = {}
        return self.recursion(digits , len(digits) , len(n) , n , 0)
