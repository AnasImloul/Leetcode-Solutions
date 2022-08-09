class Solution:
    def sumBase(self, n: int, k: int) -> int:
        cnt = 0
        while n:
            cnt += (n % k)
            n //= k
        print(cnt)
        return cnt 
