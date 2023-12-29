// Runtime: 58 ms (Top 94.85%) | Memory: 17.40 MB (Top 17.53%)

"""
https://oeis.org/A038206
"""


class Solution:
    def punishmentNumber(self, n: int) -> int:
        nums = [1, 9, 10, 36, 45, 55, 
        82, 91, 99, 100, 235, 297, 
        369, 370, 379, 414, 657, 
        675, 703, 756, 792, 909, 
        918, 945, 964, 990, 991, 
        999, 1000]
        ans = 0
        for num in nums:
            if n >= num:
                ans += num**2
            else:
                break
        return ans
