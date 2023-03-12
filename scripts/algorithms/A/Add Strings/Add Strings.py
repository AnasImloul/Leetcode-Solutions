class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        def func(n):
            value = {'0':0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
            result = 0
            for digit in n:
                result = 10 * result + value[digit]

            return result

        ans = func(num1) + func(num2)
        return str(ans)