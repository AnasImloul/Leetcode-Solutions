# Runtime: 201 ms (Top 18.42%) | Memory: 15.8 MB (Top 36.40%)
class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        currentNumber = 0
        operator = '+'
        operations = '+-/*'
        for i in range(len(s)):
            ch = s[i]
            if ch.isdigit():
                currentNumber = currentNumber * 10 + int(ch)

            if ch in operations or i == len(s) - 1:
                if operator == '+':
                    stack.append(currentNumber)

                elif operator == '-':
                    stack.append(-currentNumber)

                elif operator == '*':
                    stack.append(stack.pop() * currentNumber)

                elif operator == '/':
                    stack.append(int(stack.pop()/currentNumber))

                currentNumber =0
                operator = ch

        return sum(stack)
