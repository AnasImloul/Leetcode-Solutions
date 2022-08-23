# Runtime: 40 ms (Top 73.88%) | Memory: 13.8 MB (Top 97.86%)
class Solution:
    def sumBase(self, n: int, k: int) -> int:
        cnt = 0
        while n:
            cnt += (n % k)
            n //= k
        print(cnt)
        return cnt