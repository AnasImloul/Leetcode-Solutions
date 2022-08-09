class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        res = []
        for num in nums:
            while res and gcd(res[-1], num) > 1:
                num = lcm(res[-1], num)
                res.pop()
            res.append(num)
        return res
