# Runtime: 0 ms (Top 100.00%) | Memory: 19.30 MB (Top 45.02%)

class Solution:
    def splitNum(self, num: int) -> int:

        digits, ans = [], 0

        while num:
            digits.append(num%10)
            num//= 10

        if len(digits)%2: digits.append(0)

        digits.sort()

        for i in range(0,len(digits),2):
            ans = ans*10+digits[i]+digits[i+1]

        return ans
