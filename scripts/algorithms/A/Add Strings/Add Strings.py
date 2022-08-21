# Runtime: 67 ms (Top 46.85%) | Memory: 14.2 MB (Top 25.08%)

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        num1 = list(num1)
        num2 = list(num2)

        ans = ''
        carry = 0
        while num1 and num2:
            p = int(num1.pop()) + int(num2.pop()) + carry
            carry = p//10
            ans = str(p%10) + ans

        while num1:
            p = int(num1.pop()) + carry
            carry = p//10
            ans = str(p%10) + ans

        while num2:
            p = int(num2.pop()) + carry
            carry = p//10
            ans = str(p%10) + ans

        if carry: ans = str(carry) + ans
        return ans