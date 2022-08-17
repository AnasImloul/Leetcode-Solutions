class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        # n = 8, k = 5
        # 1 2 3 8 4 7 5 6
        # 1 1 5 4 3 2 1
        res = list(range(1,n-k+1))
        sign, val = 1, k
        for i in range(k):
            res.append(res[-1]+sign*val)
            sign *= -1
            val -= 1
        return res
